import React, { useState, useEffect } from 'react';
import { View, Text, FlatList } from 'react-native';
import axios from 'axios';
import cheerio from 'cheerio';

const AttendanceScreen = ({ enrollmentNo, dob, password }) => {
  const [attendanceData, setAttendanceData] = useState([]);
  const [isLoading, setIsLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    const fetchData = async () => {
      try {
        const response = await axios.get('https://webkiosk.juet.ac.in/index.jsp');
        const jsessionid = response.headers['set-cookie'].split(';')[0].split('=')[1];
        const body = response.data;
        const $ = cheerio.load(body);
        const captcha = $('.noselect').text().trim();

        const payload = new URLSearchParams({
          x: '',
          txtInst: 'Institute',
          InstCode: 'JUET',
          txtuType: 'Member Type',
          UserType: 'S',
          txtCode: 'Enrollment No',
          MemberCode: '211B173',
          DOB: 'DOB',
          DATE1: '31-10-2002',
          txtPin: 'Password/Pin',
          Password: 'Manan@746',
          txtCodecaptcha: 'Enter Captcha',
          txtcap: `${captcha}`,
          BTNSubmit: 'Submit'
        });

        const headers = {
          'Cookie': `switchmenu=; JSESSIONID=${jsessionid}`,
          'Host': 'webkiosk.juet.ac.in',
          'Origin': 'https://webkiosk.juet.ac.in',
        };

        await axios.post('https://webkiosk.juet.ac.in/CommonFiles/UserAction.jsp', payload, { headers });

        const attendanceResponse = await axios.get('https://webkiosk.juet.ac.in/StudentFiles/Academic/StudentAttendanceList.jsp', { headers });
        const attendanceData = attendanceResponse.data;
        const $attendance = cheerio.load(attendanceData);
        const subjects = [];

        $attendance('table tbody tr').each((i, elem) => {
          if (i <= 2) return;
          const subjectName = $attendance(elem).find('td:nth-child(2)').text().trim();
          const lecturePlusTutorialAttendance = $attendance(elem).find('td:nth-child(3) a').text().trim();
          const lectureAttendance = $attendance(elem).find('td:nth-child(4) a').text().trim();
          const tutorialAttendance = $attendance(elem).find('td:nth-child(5) a').text().trim();
          const practicalAttendance = $attendance(elem).find('td:nth-child(6) a').text().trim();

          subjects.push({
            subjectName,
            lecturePlusTutorialAttendance,
            lectureAttendance,
            tutorialAttendance,
            practicalAttendance
          });
        });

        setAttendanceData(subjects);
        setIsLoading(false);
      } catch (error) {
        console.error('Error fetching data:', error);
        setError('Error fetching data. Please try again.');
        setIsLoading(false);
      }
    };

    console.log(fetchData());
    fetchData();
  }, [enrollmentNo, dob, password]);

  return (
    <View>
      {isLoading && <Text>Loading...</Text>}
      {error && <Text style={{ color: 'red' }}>{error}</Text>}
      <Text>Attendance Data:</Text>
      <FlatList
        data={attendanceData}
        keyExtractor={(item) => item.subjectName}
        renderItem={({ item }) => (
          <View>
            <Text>{`Subject: ${item.subjectName}`}</Text>
            <Text>{`Lecture+Tutorial(%): ${item.lecturePlusTutorialAttendance}`}</Text>
            <Text>{`Lecture(%): ${item.lectureAttendance}`}</Text>
            <Text>{`Tutorial(%): ${item.tutorialAttendance}`}</Text>
            <Text>{`Practical(%): ${item.practicalAttendance}`}</Text>
            <Text>--------------------</Text>
          </View>
        )}
      />
    </View>
  );
};

export default AttendanceScreen;
