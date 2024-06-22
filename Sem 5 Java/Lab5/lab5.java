import java.util.*;
abstract class Person{
	protected int id ;
	protected String name ;
	protected String email ;

	public Person(int id , String name , String email){
		this.id = id ;
		this.name = name ;
		this.email = email ;
	}

}

class Student extends Person{
	String studentId ;
	String major ;

	Student(int id , String name , String email,String studentId , String major){
		super(id,name,email);
		this.studentId = studentId;
		this.major = major;
	}
}

class Faculty extends Person{
	String facultyId ;
	String department ;

	Faculty(int id , String name , String email,String facultyId , String department){
		super(id,name,email);
		this.facultyId = facultyID;
		this.department = department;
	}
}

interface Course{
	String getCourseCode();
	String getCourseTitle();
	int getCreditHours();
}

class dataStructure implements Course{
	String courseCode;
	String courseTitle;
	int creditHours;

	dataStructure(){
		this.courseCode = "CS102";
		this.courseTitle = "Data_Structure";
		this.creditHours = 4;
	}

	String getCourseCode(){
		return this.courseCode;
	}

	String getCourseTitle(){
		return this.courseTitle;
	}

	int getCreditHours(){
		return this.creditHours;
	}
}

class DBMS implements Course{
	String courseCode;
	String courseTitle;
	int creditHours;

	DBMS(){
		this.courseCode = "CS112";
		this.courseTitle = "Database_Management";
		this.creditHours = 3;
	}

	String getCourseCode(){
		return this.courseCode;
	}

	String getCourseTitle(){
		return this.courseTitle;
	}

	int getCreditHours(){
		return this.creditHours;
	}
}

class OS implements Course{
	String courseCode;
	String courseTitle;
	int creditHours;

	OS(){
		this.courseCode = "CS105";
		this.courseTitle = "Operating_systems";
		this.creditHours = 3;
	}

	String getCourseCode(){
		return this.courseCode;
	}

	String getCourseTitle(){
		return this.courseTitle;
	}

	int getCreditHours(){
		return this.creditHours;
	}
}

class CN implements Course{
	String courseCode;
	String courseTitle;
	int creditHours;

	CN(){
		this.courseCode = "CS166";
		this.courseTitle = "Computer_Networks";
		this.creditHours = 3;
	}

	String getCourseCode(){
		return this.courseCode;
	}

	String getCourseTitle(){
		return this.courseTitle;
	}

	int getCreditHours(){
		return this.creditHours;
	}
}

class compilerDesign implements Course{
	String courseCode;
	String courseTitle;
	int creditHours;

	compilerDesign(){
		this.courseCode = "CS111";
		this.courseTitle = "Compiler_Design";
		this.creditHours = 4;
	}

	String getCourseCode(){
		return this.courseCode;
	}

	String getCourseTitle(){
		return this.courseTitle;
	}

	int getCreditHours(){
		return this.creditHours;
	}
}

class Enrollment{
    Student student;
    List<Course> enrolledCourse;
    Enrollment(Student student){
        this.student=student;
        enrolledCourse=new ArrayList <>();
    }
    void enrolled(Course course){
        enrolledCourse.add(course);
    }
    int totalCreditHour(){
        int total = 0;
        for (Course course : enrolledCourse) {
            total += course.getCreditHours();
        }
        return total;
    }
}

class GradeBook{
	// Maintain a mapping of students and their course grades.
	// Calculate and display the GPA for each student.
	Map<Student,List<Map<Course,Double>>> grade;
	GradeBook(Student student){
		this.student = student;
		grade = new HashMap<Student,List<Map<Course,Double>>>();
	}
	public void addGrade(Course course , Double gp){
		grade[student].put(course,gp);
	}

	double mark(Student student,GradeBook grade){
		double avg = 0;
		for(GradeBook x : grade){
			for(Double y : x[student]){
				avg += y;
			}
		}
		return avg;
	}

}

class UniversityApp{
	public static void main(String[] args) {
		
	}
} 