from bs4 import BeautifulSoup

html = '''<HTML>

<head>
        <TITLE>#### JUET [ Student Class Attendance ] </TITLE>
        <script type="text/javascript" src="../js/sortabletable.js"></script>
        <link type="text/css" rel="StyleSheet" href="../css/sortabletable.css" />

        <script language="JavaScript" type="text/javascript">
                <!-- 
                  if (top != self) top.document.title = document.title;
                 ->
        </script>
        <script>
                if (window.history.forward(1) != null)
                        window.history.forward(1);
        </script>
</head>


<body aLink=#ff00ff bgcolor=#fce9c5 rightmargin=0 leftmargin=0 topmargin=0 bottommargin=0>

        <table width="100%" ALIGN=CENTER bottommargin=0 topmargin=0>
                <tr>
                        <TD align=middle>
                                <font color="#a52a2a" style="FONT-SIZE: medium; FONT-FAMILY: verdana"><b>Student
                                                Attendance</b></font>
                        </td>
                </tr>
        </table>
        <form name="frm" method=get>
                <input id="x" name="x" type=hidden>
                <table width=100% rules=groups cellspacing=1 cellpadding=1 align=center border=1>
                        <tr>
                                <td>
                                        <font color=black face=arial size=2><STRONG> Name:&nbsp;</STRONG></font>Manan
                                        Jain[211B173]
                                </td>
                                <td>
                                        <font color=black face=arial size=2><STRONG>Course/Branch:&nbsp;</STRONG></font>
                                        B.T.(CSE)
                                </td>
                                <td>
                                        <font color=black face=arial size=2><STRONG>Current Semester:&nbsp;</STRONG>
                                        </font>5
                                </td>
                        </tr>
                        <tr>
                                <td>
                                        <font color=black face=arial size=2><STRONG>Exam Code</STRONG></font>

                                        <select name=exam tabindex="0" id="exam" style="WIDTH: 140px">

                                                <OPTION Selected Value=2023ODDSEM>2023ODDSEM</option>

                                        </select>
                                </td>
                                <td colspan=2>
                                        <input type="submit" value="View Attendance">
                                </td>
                        </tr>
                </table>
        </form>

        <TABLE align=center rules=Rows class="sort-table" id="table-1" cellSpacing=1 cellPadding=1 width="98%" border=1>
                <thead>
                        <tr bgcolor="#c00000">
                                <td Title="Click on SNo to sort"><b>
                                                <font color="White">SNo</font>
                                        </b></td>
                                <td Title="Click on Subject to Sort"><b>
                                                <font color="White">Subject</font>
                                        </b></td>
                                <!--  <td Title="Click on Subject to Sort"><b><font color="White">Employee </font></b></td>-->
                                <td Title="Click on Lecture+Tutorial(%) to Sort"><b>
                                                <font color="White">Lecture+Tutorial(%)</font>
                                        </b></td>
                                <td align=center Title="Click on Lecture(%) to Sort"><b>
                                                <font color="White">Lecture(%)</font>
                                        </b></td>
                                <td align=center Title="Click on Tutorial(%) to Sort"><b>
                                                <font color="White">Tutorial(%)</font>
                                        </b></td>
                                <td align=center Title="Click on Practical(%) to Sort"><b>
                                                <font color="White">Practical(%)</font>
                                        </b></td>
                        </tr>
                </thead>
                <tbody>

                        <tr>
                                <td>1</td>
                                <td>ADVANCED PROGRAMMING LAB-2 - 18B17CI573</td>

                                <td>&nbsp;</td>
                                <td>&nbsp;</td>

                                <td>&nbsp;</td>

                                <td align=center><a Title="View Date wise Practical Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=200004&amp;LTP=P&amp;&amp;mRegConfirmDate=24-07-2023&amp;prevPFSTID=&amp;mPFSTID=JUET2300482'>94</a>
                                </td>

                        </tr>

                        <tr>
                                <td>2</td>
                                <td>CONCEPT OF ECONOMICS - 21B14HS547</td>

                                <td align=center><a Title="View Date wise Lecture + Tutorial Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=210036&amp;LTP=LT&amp;mRegConfirmDate=24-07-2023&amp;prevTFSTID=&amp;prevLFSTID=&amp;mLFSTID=JUET2301135&amp;mTFSTID=JUET2301147'>92</a>
                                </td>

                                <td align=center><a Title="View Date wise Lecture Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=210036&amp;LTP=L&amp;&amp;mRegConfirmDate=24-07-2023&amp;prevLFSTID=&amp;mLFSTID=JUET2301135'>
                                                <font color=blue>88</font>
                                        </a></td>

                                <td align=center><a Title="View Date wise Tutorial Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=210036&amp;LTP=T&amp;mRegConfirmDate=24-07-2023&amp;prevTFSTID=&amp;mTFSTID=JUET2301147'>100</a>
                                </td>

                                <td>&nbsp;</td>

                        </tr>

                        <tr>
                                <td>3</td>
                                <td>FULL STACK DEVELOPMENT - 21B14CI742</td>

                                <td align=center><a Title="View Date wise Lecture + Tutorial Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=220049&amp;LTP=LT&amp;mRegConfirmDate=24-07-2023&amp;prevTFSTID=&amp;prevLFSTID=&amp;mLFSTID=JUET2300722&amp;mTFSTID='>89</a>
                                </td>

                                <td align=center><a Title="View Date wise Lecture Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=220049&amp;LTP=L&amp;&amp;mRegConfirmDate=24-07-2023&amp;prevLFSTID=&amp;mLFSTID=JUET2300722'>
                                                <font color=blue>89</font>
                                        </a></td>

                                <td>&nbsp;</td>

                                <td>&nbsp;</td>

                        </tr>

                        <tr>
                                <td>4</td>
                                <td>MINOR PROJECT- 1 - 18B19CI591</td>

                                <td>&nbsp;</td>
                                <td>&nbsp;</td>

                                <td>&nbsp;</td>

                                <td>&nbsp;</td>

                        </tr>

                        <tr>
                                <td>5</td>
                                <td>NANO SCIENCE - 18B14PH542</td>

                                <td align=center><a Title="View Date wise Lecture + Tutorial Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=210047&amp;LTP=LT&amp;mRegConfirmDate=24-07-2023&amp;prevTFSTID=&amp;prevLFSTID=&amp;mLFSTID=JUET2300415&amp;mTFSTID='>92</a>
                                </td>

                                <td align=center><a Title="View Date wise Lecture Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=210047&amp;LTP=L&amp;&amp;mRegConfirmDate=24-07-2023&amp;prevLFSTID=&amp;mLFSTID=JUET2300415'>
                                                <font color=blue>92</font>
                                        </a></td>

                                <td>&nbsp;</td>

                                <td>&nbsp;</td>

                        </tr>

                        <tr>
                                <td>6</td>
                                <td>OPEN SOURCE SOFTWARE LAB - 18B17CI507</td>

                                <td>&nbsp;</td>
                                <td>&nbsp;</td>

                                <td>&nbsp;</td>

                                <td align=center><a Title="View Date wise Practical Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=200003&amp;LTP=P&amp;&amp;mRegConfirmDate=24-07-2023&amp;prevPFSTID=&amp;mPFSTID=JUET2300647'>100</a>
                                </td>

                        </tr>

                        <tr>
                                <td>7</td>
                                <td>PROBABILITY THEORY AND RANDOM PROCESSES - 18B11MA511</td>

                                <td align=center><a Title="View Date wise Lecture + Tutorial Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=190023&amp;LTP=LT&amp;mRegConfirmDate=24-07-2023&amp;prevTFSTID=&amp;prevLFSTID=&amp;mLFSTID=JUET2300915&amp;mTFSTID=JUET2300928'>94</a>
                                </td>

                                <td align=center><a Title="View Date wise Lecture Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=190023&amp;LTP=L&amp;&amp;mRegConfirmDate=24-07-2023&amp;prevLFSTID=&amp;mLFSTID=JUET2300915'>
                                                <font color=blue>96</font>
                                        </a></td>

                                <td align=center><a Title="View Date wise Tutorial Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=190023&amp;LTP=T&amp;mRegConfirmDate=24-07-2023&amp;prevTFSTID=&amp;mTFSTID=JUET2300928'>87</a>
                                </td>

                                <td>&nbsp;</td>

                        </tr>

                        <tr>
                                <td>8</td>
                                <td>THEORY OF COMPUTATION - 18B11CI511</td>

                                <td align=center><a Title="View Date wise Lecture + Tutorial Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=200002&amp;LTP=LT&amp;mRegConfirmDate=24-07-2023&amp;prevTFSTID=&amp;prevLFSTID=&amp;mLFSTID=JUET2300660&amp;mTFSTID=JUET2300672'>93</a>
                                </td>

                                <td align=center><a Title="View Date wise Lecture Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=200002&amp;LTP=L&amp;&amp;mRegConfirmDate=24-07-2023&amp;prevLFSTID=&amp;mLFSTID=JUET2300660'>
                                                <font color=blue>92</font>
                                        </a></td>

                                <td align=center><a Title="View Date wise Tutorial Attendance" target=_New
                                                href='ViewDatewiseLecAttendance.jsp?EXAM=2023ODDSEM&amp;CTYPE=R&amp;SC=200002&amp;LTP=T&amp;mRegConfirmDate=24-07-2023&amp;prevTFSTID=&amp;mTFSTID=JUET2300672'>100</a>
                                </td>

                                <td>&nbsp;</td>

                        </tr>

                </tbody>
        </table>
        <table>
                <!--
<tr><td><font size=2 color=blue face=verdana><B>&nbsp;Hint:</B> </font>
 <UL>
        <font face="verdana" size=2 color=Green><LI>
        <B>If the '%' attendance of Lecture, Tutorial or Practical is less than 50%, It will appear in blue color.</B>
        <LI><B>By clicking on '%' link you can view attendance datewise.</B>
        <LI><B>In case of any doubt, contact respective faculty.</B></font>
 </UL>

</font></td></tr> -->

                <!--
<tr><td><font size=2 color=blue face=verdana><B>&nbsp;Note:</B>
 <UL>
        <font face="verdana" size=2 color=black>
        <LI><B>Attendance of Monday to Wednesday  will be updated by Saturday of the current week. </B>
        <LI><B>Attendance of Thursday to Saturday will be updated by Wednesday of the following week. </B>
</font>
 </UL>
</td></tr>

-->
        </table>
        <script type="text/javascript">
                var st1 = new SortableTable(document.getElementById("table-1"), ["Number", "CaseInsensitiveString", "CaseInsensitiveString", "CaseInsensitiveString", "CaseInsensitiveString"]);
        </script>

</body>

</html>'''

soup = BeautifulSoup(html, 'html.parser')

# print(soup.find_all('td')) #Trying to print docs and maintaining the format


# print(soup.prettify()) Prints the HTML DOC as a WHOLE
#print(soup.text) #prints the HTML PAGE DATA 



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
            "Lecture+Tutorial(%)": lecture_tutorial_percentage,
            "Lecture(%)": lecture_percentage,
            "Tutorial(%)": tutorial_percentage,
            "Practical(%)": practical_percentage
        }

        attendance_data.append(attendance_row)

# Print the extracted attendance data
for row_data in attendance_data:
    print(row_data)
    

