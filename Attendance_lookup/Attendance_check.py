import requests
import creds
from bs4 import BeautifulSoup

def displayAttendance(html):
    soup = BeautifulSoup(html, 'html.parser')
    table = soup.find(id="table-1")
    attendance_data = []

    for row in table.find('tbody').find_all('tr'):
        columns = row.find_all('td')
        if len(columns) >= 6: 
            sno = columns[0].text.strip()
            subject = columns[1].text.strip()
            lecture_tutorial_percentage = columns[2].text.strip()
            lecture_percentage = columns[3].text.strip()
            tutorial_percentage = columns[4].text.strip()
            practical_percentage = columns[5].text.strip()

            attendance_row = {
                "SNo": sno,
                "Subject": subject,
                "L+T(%)": lecture_tutorial_percentage,
                "L(%)": lecture_percentage,
                "T(%)": tutorial_percentage,
                "Lab(%)": practical_percentage
            }

            attendance_data.append(attendance_row)

    # Print the extracted attendance data
    for row_data in attendance_data:
        print(row_data)

cookies = {
    'switchmenu': '',
    'JSESSIONID': '',
}

headers = {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8',
    'Accept-Language': 'en-US,en;q=0.8',
    'Cache-Control': 'max-age=0',
    'Connection': 'keep-alive',
    'Content-Type': 'application/x-www-form-urlencoded',
    # 'Cookie': 'switchmenu=; JSESSIONID=8JzdDyKfkwwKeDXJdPyuoFAt.undefined',
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
}

data = {
    'x': '',
    'txtInst': 'Institute',
    'InstCode': 'JUET',
    'txtuType': 'Member Type',
    'UserType': 'S',
    'txtCode': 'Enrollment No',
    'MemberCode': '',
    'DOB': 'DOB',
    'DATE1': '',
    'txtPin': 'Password/Pin',
    'Password': '',
    'txtCodecaptcha': 'Enter Captcha     ',
    'txtcap': '',
    'BTNSubmit': 'Submit',
}

with requests.Session() as s:
    login_url = 'https://webkiosk.juet.ac.in/index.jsp'
    r = s.get(login_url)
    # initial_response = s.get('https://webkiosk.juet.ac.in/')
    jsessionid = r.cookies.get('JSESSIONID')
    soup = BeautifulSoup(r.text,'html.parser')
    captcha = soup.find(class_="noselect").text
    # print(captcha)
    data['txtcap'] = captcha
    cookies['JSESSIONID'] = jsessionid
    # print(jsessionid)
    data['MemberCode'] = creds.eNo
    data['DATE1'] = creds.dob
    data['Password'] = creds.code
    s.post('https://webkiosk.juet.ac.in/CommonFiles/UserAction.jsp', cookies=cookies, headers=headers, data=data)
    r = s.get('https://webkiosk.juet.ac.in/StudentFiles/Academic/StudentAttendanceList.jsp')
    # print(r.text)
    html = r.text
    displayAttendance(html)
    

#response = requests.post('https://webkiosk.juet.ac.in/CommonFiles/UserAction.jsp', cookies=cookies, headers=headers, data=data)