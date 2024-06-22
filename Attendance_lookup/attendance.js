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

const session = axios.create({
    headers: {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8',
    'Accept-Language': 'en-US,en;q=0.8',
    'Cache-Control': 'max-age=0',
    'Connection': 'keep-alive',
    'Content-Type': 'application/x-www-form-urlencoded',
    'Origin': 'https://webkiosk.juet.ac.in',
    'Referer': 'https://webkiosk.juet.ac.in/',
    'Sec-Fetch-Dest': 'document',
    'Sec-Fetch-Mode': 'navigate',
    'Sec-Fetch-Site': 'same-origin',
    'Sec-Fetch-User': '?1',
    'Sec-GPC': '1',
    'Upgrade-Insecure-Requests': '1',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/117.0.0.0 Safari/537.36',
    'sec-ch-ua': '"Brave";v="117", "Not;A=Brand";v="8", "Chromium";v="117"',
    'sec-ch-ua-mobile': '?0',
    'sec-ch-ua-platform': '"Windows"',
    },
});

const headers = {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8',
    'Accept-Language': 'en-US,en;q=0.8',
    'Cache-Control': 'max-age=0',
    'Connection': 'keep-alive',
    'Content-Type': 'application/x-www-form-urlencoded',
    'Origin': 'https://webkiosk.juet.ac.in',
    'Referer': 'https://webkiosk.juet.ac.in/',
    'Sec-Fetch-Dest': 'document',
    'Sec-Fetch-Mode': 'navigate',
    'Sec-Fetch-Site': 'same-origin',
    'Sec-Fetch-User': '?1',
    'Sec-GPC': '1',
    'Upgrade-Insecure-Requests': '1',
    'User-Agent': 'Mozilla/5.0 (Windows NT  10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/117.0.0.0 Safari/537.36',
    'sec-ch-ua': '"Brave";v="117", "Not;A=Brand";v="8", "Chromium";v="117"',
    'sec-ch-ua-mobile': '?0',
    'sec-ch-ua-platform': '"Windows"',
};

async function main() {
    const loginUrl = 'https://webkiosk.juet.ac.in/index.jsp';
    const response = await session.get(loginUrl);
    const jsessionid = response.headers['set-cookie'][0].split(';')[0].split('=')[1];
    const $ = cheerio.load(response.data);
    const captcha = $('.noselect').text();
    // console.log(captcha);

    const cookies = {
        switchmenu: '',
        JSESSIONID: jsessionid,
    }

    // console.log(cookies)
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

    console.log('yaha')
    const commonFilesUrl = 'https://webkiosk.juet.ac.in/CommonFiles/UserAction.jsp';
    await session.post(commonFilesUrl, data, {headers: headers, cookies:cookies}).then(async () =>{
        console.log('yaha1212')
        const attendanceUrl = 'https://webkiosk.juet.ac.in/StudentFiles/Academic/StudentAttendanceList.jsp';
        const response = await session.get(attendanceUrl, {headers: headers, cookies:cookies});
        const html = response.data;
        console.log(html);
        displayAttendance(html);
    });
}

console.log("FETCHING");

main().catch(error => {
    console.error('Error:', error);
});
