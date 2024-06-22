const superagent = require('superagent').agent();

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
    txtcap: '',
    BTNSubmit: 'Submit',
};

const login_url = 'https://webkiosk.juet.ac.in/index.jsp';

const att_page = async () =>{

    // let cap = await superagent.get(login_url)
    // jsessionid = cap.cookies.get('JSESSIONID')


    // let page = await superagent
    // .post('https://webkiosk.juet.ac.in/index.jsp')
    // .send({data})

    let page = await superagent.get(login_url);
    console.log(page.text);

}

att_page();