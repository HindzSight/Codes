import java.util.*;

public class university_management {
    abstract static class Person {
        final int id;
        final String name;
        final String email;

        Person(int id_, String name_, String email_) {
            this.id = id_;
            this.name = name_;
            this.email = email_;
        }
    }

    static class Student extends Person {
        String studentId;
        String major;

        Student(int id_, String name_, String email_, String studentid_, String major) {
            super(id_, name_, email_);
            this.major = major;
            this.studentId = studentid_;
        }
    }

    static class Faculty extends Person {
        String facultyId;
        String department;

        Faculty(int id_, String name_, String email_, String facultyid_, String department) {
            super(id_, name_, email_);
            this.facultyId = facultyid_;
            this.department = department;
        }
    }

    abstract static class CourseInfo {
        final int courseHours;
        final String courseCode;
        final String courseTitle;

        CourseInfo(String code, String title, int hour) {
            this.courseCode = code;
            this.courseHours = hour;
            this.courseTitle = title;
        }
    }

    interface Course {
        String getCourseCode();

        String getCourseTitle();

        int getCourseHours();
    }

    static class DBMS extends CourseInfo implements Course {
        DBMS(String code, String title, int hour) {
            super(code, title, hour);
        }

        public String getCourseCode() {
            return courseCode;
        }

        public String getCourseTitle() {
            return courseTitle;
        }

        public int getCourseHours() {
            return courseHours;
        }
    }

    static class Algorithms extends CourseInfo implements Course {
        Algorithms(String code, String title, int hour) {
            super(code, title, hour);
        }

        public String getCourseCode() {
            return courseCode;
        }

        public String getCourseTitle() {
            return courseTitle;
        }

        public int getCourseHours() {
            return courseHours;
        }
    }

    static class OperatingSystems extends CourseInfo implements Course {
        OperatingSystems(String code, String title, int hour) {
            super(code, title, hour);
        }

        public int getCourseHours() {
            return courseHours;
        }

        public String getCourseTitle() {
            return courseTitle;
        }

        public String getCourseCode() {
            return courseCode;
        }
    }

 static class Networking extends CourseInfo implements Course{
 Networking(String code, String title, int hour) {
 super(code, title, hour);
 }
 public int getCourseHours() {
 return courseHours;
 }
 public String getCourseTitle() {
 return courseTitle;
 }
 public String getCourseCode() {
 return courseCode;
 }
 }

    static class DataStructure extends CourseInfo implements Course {
        DataStructure(String code, String title, int hour) {
            super(code, title, hour);
        }

        public int getCourseHours() {
            return courseHours;
        }

        public String getCourseTitle() {
            return courseTitle;
        }

        public String getCourseCode() {
            return courseCode;
        }
    }

    static class Enrollment {
        private Student student;
        private List<Course> enrolledCourses = new ArrayList<>();

        public Enrollment(Student student) {
            this.student = student;
        }

        public void enrollInCourse(Course course) {
            enrolledCourses.add(course);
        }

        public int getTotalCreditHours() {
            int total_credits = 0;
            for (Course course : enrolledCourses) {
                total_credits += course.getCourseHours();
            }
            return total_credits;
        }
    }

    static class GradeBook {
        private Map<Student, Map<Course, String>> studentgrades = new HashMap<>();

        public void assignGrade(Student student, Course course, String grade) {
            studentgrades.computeIfAbsent(student, k -> new HashMap<>()).put(course, grade);
        }

 public double calculateGPA(Student student) {
 Map<Course, String> grades =
studentgrades.getOrDefault(student, Collections.emptyMap());
 if (grades.isEmpty()) {
 return 0.0; // No grades available

 }
 int totalCredits = 0;
 double totalGradePoints = 0.0;
 for (Map.Entry<Course, String> entry : grades.entrySet()) {
 Course course = entry.getKey();
 String grade = entry.getValue();
 int creditHours = course.getCourseHours();
 double gradePoints = calculateGradePoints(grade);
 totalCredits += creditHours;
 totalGradePoints += creditHours * gradePoints;
 }
 return totalGradePoints / totalCredits;
 }

        private double calculateGradePoints(String grade) {
            // grading scale logic
            switch (grade) {
                case "A":
                    return 10.0;
                case "B":
                    return 9.0;
                case "C":
                    return 8.0;
                case "D":
                    return 7.0;
                case "E":
                    return 6.0;
                case "F":
                    return 5.0;
                default:
                    return 0;
            }
        }
    }

 public static void main(String[] args) {
 Student student1 = new Student(1, "John", "john@example.com",
"S12345", "Computer Science");
 Faculty faculty1 = new Faculty(101, "Dr. Smith","smith@example.com", "F56789", "Computer Science");
 Course dataStructure = new DataStructure("CS101", "DataStructure", 3);
 Course dbms = new DBMS("CS102", "Database Management", 3);
 Enrollment johnEnrollment = new Enrollment(student1);
 johnEnrollment.enrollInCourse(dataStructure);
 johnEnrollment.enrollInCourse(dbms);
 GradeBook gradeBook = new GradeBook();
 gradeBook.assignGrade(student1, dataStructure, "A");
 gradeBook.assignGrade(student1, dbms, "B");
 System.out.println(student1);
 System.out.println("Enrolled Courses: " +
johnEnrollment.getTotalCreditHours() + " credit hours");
 System.out.println("GPA: " + gradeBook.calculateGPA(student1));
 }
}