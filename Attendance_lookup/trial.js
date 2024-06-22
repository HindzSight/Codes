const axios = require('axios');
const cheerio = require('cheerio');

async function displayAttendance(html) {
    const $ = cheerio.load(html);
    const table = $('#table-1');
    const attendanceData = [];

    table.find('tbody tr').each((index, row) => {
        const columns = $(row).find('td');
        if (columns.length >= 6) {
            const sno = columns.eq(0).text().trim();
            const subject = columns.eq(1).text().trim();
            const lectureTutorialPercentage = columns.eq(2).text().trim();
            const lecturePercentage = columns.eq(3).text().trim();
            const tutorialPercentage = columns.eq(4).text().trim();
            const practicalPercentage = columns.eq(5).text().trim();

            const attendanceRow = {
                SNo: sno,
                Subject: subject,
                'Lecture+Tutorial(%)': lectureTutorialPercentage,
                'Lecture(%)': lecturePercentage,
                'Tutorial(%)': tutorialPercentage,
                'Practical(%)': practicalPercentage,
            };

            attendanceData.push(attendanceRow);
        }
    });

    // Print the extracted attendance data
    attendanceData.forEach(rowData => {
        console.log(rowData);
    });
}

async function main() {
    const session = axios.create();

    const loginUrl = 'https://webkiosk.juet.ac.in/index.jsp';
    const response = await session.get(loginUrl);
    // const jsessionid = response.headers['set-cookie'][0].split(';')[0].split('=')[1];
    const $ = cheerio.load(response.data);
    const captcha = $('.noselect').text();

    const data = {
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
        txtcap: captcha,
        BTNSubmit: 'Submit',
    };

    const commonFilesUrl = 'https://webkiosk.juet.ac.in/CommonFiles/UserAction.jsp';
    await session.post(commonFilesUrl, data, { headers: response.headers }).then(async ()=>{
        
        const attendanceUrl = 'https://webkiosk.juet.ac.in/StudentFiles/Academic/StudentAttendanceList.jsp';
        const attendanceResponse = await session.get(attendanceUrl, { headers: response.headers });
        const html = attendanceResponse.data;
        console.log(html);
        displayAttendance(html);
    });

}

console.log("FETCHING");

main().catch(error => {
    console.error('Error:', error);
});
