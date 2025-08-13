#include <iostream>
#include <string>
using namespace std;
class Student {
private:
	string name;
	string rollno;
	int age;
	string contact;
public:
	Student() {
		name = "";
		rollno = "";
		age = 0;
		contact = "";
	}
	Student(string Name, string roll, int Age, string Contact) {
		name = Name;
		rollno = roll;
		age = Age;
		contact = Contact;
	}
	void operator =(Student& obj) {
		this->name = obj.name;
		this->rollno = obj.rollno;
		this->age = obj.age;
		this->contact = obj.contact;
	}
	void setRoll(string rollno) {
		this->rollno = rollno;
	}
	void setName(string Name) {
		this->name = Name;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setContact(string phoneno) {
		this->contact = phoneno;
	}
	string getRollno() {
		return this->rollno;
	}
	string getContact() {
		return this->contact;
	}
	string getName() {
		return this->name;
	}
	int getAge() {
		return this->age;
	}
	void display() {
		cout << "Name: " << this->name << endl;
		cout << "Roll no: " << this->rollno << endl;
		cout << "Age: " << this->age << endl;
		cout << "Contact no: " << this->contact << endl;
	}
	~Student() {
	}
};
string temp1_name;
string temp1_contact;
int temp1_age;
class studentEnrollment {
private:
	Student* std;
	int size;
	int capacity;
	static studentEnrollment* se;
	bool searchStudent(string s) {
		for (int i = 0; i < size; i++) {
			if (s == std[i].getRollno()) {
				return true;
			}
		}
		return false;
	}
	studentEnrollment() {
		capacity = 1;
		std = new Student[capacity];
		size = 0;
	}
public:
	static studentEnrollment* getInstance() {
		if (se == NULL) {
			se = new studentEnrollment;
		}
		return se;
	}
	bool addStudent(Student& s) {
		if (searchStudent(s.getRollno()) == true) {
			cout << "\nStudent already enrolled in University\n";
			return false;
		}
		if (size < capacity) {
			std[size++] = s;
		}
		else {
			capacity = capacity * 2;
			Student* temp = new Student[capacity];
			for (int i = 0; i < size; i++) {
				temp[i] = std[i];
			}
			delete[]std;
			std = temp;
			temp = nullptr;
			std[size++] = s;
		}
		cout << "\nStudent added\n";
		return true;
	}
	bool removeStudent(string s) {
		bool flag = false;
		if (size > 0) {
			for (int i = 0; i < size; i++) {
				if (s == std[i].getRollno()) {
					size--;
					flag = true;
					for (int j = i; j < size; j++) {
						std[j] = std[j + 1];
					}
					cout << "\nStudent removed\n";
					return true;
				}
			}
			if (flag == false) {
				cout << "\nStudent does not exist\n";
				return false;
			}
		}
		else {
			cout << "No student is currently enrolled\n";
			return false;
		}
	}
	bool editDetails(string S) {
		if (searchStudent(S) == true) {
			for (int i = 0; i < size; i++) {
				if (S == std[i].getRollno()) {
					string t_name, contact, r_no;
					int age;
					cout << "Enter new roll_no\n";
					getline(cin, r_no);
					cout << "Enter new name\n";
					getline(cin, t_name);
					cout << "Enter new age\n";
					cin >> age;
					cin.ignore();
					cout << "Enter new contact\n";
					getline(cin, contact);
					std[i].setName(t_name);
					std[i].setAge(age);
					std[i].setContact(contact);
					std[i].setRoll(r_no);
					cout << "\nDetails updated\n";
					temp1_name = t_name;
					temp1_contact = contact;
					temp1_age = age;
					return true;
				}	
			}
		}
		else {
			cout << "\nStudent does not exist\n";
			return false;
		}
	}
	void display() {
		if (size != 0) {
			cout << "\nStudents enrolled in the university are: \n";
			for (int i = 0; i < size; i++) {
				cout << "\nInformation of Student " << i + 1 << " is given as:\n";
				std[i].display();
			}
		}
	}
	~studentEnrollment() {
		delete[]std;
		std = nullptr;
	}
};
class Course {
private:
	string code;
	string name;
	string instructor;
	int credits;
	int capacity = 50;
	string* enrolled_std = new string[capacity];
	int size;
	bool searchStudent(string std) {
		for (int i = 0; i < size; i++) {
			if (std == enrolled_std[i]) {
				return true;
			}
		}
		return false;
	}
public:
	Course() {
		code = "";
		name = "";
		instructor = "";
		credits = 0;
		size = 0;
	}
	Course(string code, string name, string instructor, int credits) {
		this->code = code;
		this->name = name;
		this->instructor = instructor;
		this->credits = credits;
		this->size = 0;
	}
	void operator =(Course& obj) {
		this->code = obj.code;
		this->name = obj.name;
		this->instructor = obj.instructor;
		this->credits = obj.credits;
		this->size = obj.size;
		this->capacity = obj.capacity;
		this->enrolled_std = new string[capacity];
		for (int i = 0; i < size; i++) {
			this->enrolled_std[i] = obj.enrolled_std[i];
		}

	}
	void addStudent(string std) {
		if (searchStudent(std) == true) {
			cout << "\nStudent already enrolled in course\n";
			return;
		}
		if (size < capacity) {
			enrolled_std[size++] = std;
			cout << "\nStudent added to the course\n";
		}
		else {
			cout << "\nCourse Capacity is full you can not add student\n";
		}
	}
	void removeStudent(string std) {
		if (searchStudent(std) == true) {
			for (int i = 0; i < size; i++) {
				if (std == enrolled_std[i]) {
					size--;
					for (int j = i; j < size; j++) {
						enrolled_std[j] = enrolled_std[j + 1];
					}
					cout << "\nStudent removed from the course\n";
					break;
				}
			}
		}
		else {
			cout << "\nStudent does not exist\n";
		}
	}
	string getCode() {
		return this->code;
	}
	string getName() {
		return this->name;
	}
	string* getallStudent()
	{
		return enrolled_std;
	}
	void display() {
		cout << "\nCode: " << this->code;
		cout << "\nCourse name: " << this->name;
		cout << "\nInstructor: " << this->instructor;
		cout << "\nCredit :" << this->credits;
		if (size > 0) {
			cout << "\nEnrolled Student's roll nos are:\n";
			for (int i = 0; i < size; i++) {
				cout << enrolled_std[i];
				cout << endl;
			}
		}
	}
	~Course() {
		/*delete[]enrolled_std;
		enrolled_std = nullptr;*/
	}
};
class CourseCatalogue {
private:
	Course* availableCourses;
	int size;
	int capacity;
	static CourseCatalogue* CC;
	bool searchCourse(string c) {
		for (int i = 0; i < size; i++) {
			if (c == availableCourses[i].getCode()) {
				return true;
			}
		}
		return false;
	}
public:
	Course search(string code) {
		for (int i = 0; i < size; i++) {
			if (code == availableCourses[i].getCode()) {
				return availableCourses[i];
			}
		}
		Course temp;
		return temp;
	}
	CourseCatalogue() {
		capacity = 1;
		availableCourses = new Course[capacity];
		size = 0;
	}
public:
	static CourseCatalogue* getInstance() {
		if (CC == NULL) {
			CC = new CourseCatalogue;

		}
		return CC;
	}
	void addCourse(Course& c) {
		if (this->searchCourse(c.getCode()) == true) {
			cout << "\nCourse already registered in University\n";
			return;
		}
		if (size < capacity) {
			availableCourses[size++] = c;
		}
		else {
			capacity = capacity * 2;
			Course* temp = new Course[capacity];
			for (int i = 0; i < size; i++) {
				temp[i] = availableCourses[i];
			}
			delete[]availableCourses;
			availableCourses = temp;
			temp = nullptr;
			availableCourses[size++] = c;
		}
		cout << "\nCourse added\n";
	}
	void removeCourse(string c) {
		if (searchCourse(c) == true) {
			for (int i = 0; i < size; i++) {
				if (c == availableCourses[i].getCode()) {
					size--;
					for (int j = i; j < size; j++) {
						availableCourses[j] = availableCourses[j + 1];
					}
					cout << "\nCourse removed from the catalogue\n";
					break;
				}
			}
		}
		else {
			cout << "\nCourse does not exist\n";
		}
	}
	void display() {
		cout << "\nAvailable Courses in the university are: \n";
		for (int i = 0; i < size; i++) {
			cout << "\nInformation of Course " << i + 1 << " is given as:\n";
			availableCourses[i].display();
		}
	}
	void addstudentToaCourse(string rollno, string code)
	{
		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				if (availableCourses[i].getCode() == code)
					availableCourses[i].addStudent(rollno);
				return;
			}
		}
		return;
	}
	void removestudentfromaCourse(string rollno, string code)
	{
		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				if (availableCourses[i].getCode() == code)
					availableCourses[i].removeStudent(rollno);
				return;
			}
		}
		return;
	}
	~CourseCatalogue() {
		delete[]availableCourses;
		availableCourses = nullptr;
	}
};
class studentinfoManagament {
private:
	Student* s;
	Course* c;
	double* Marks;
	double* Attendance;
	int count;
	int capacity;
public:
	void operator =(studentinfoManagament& a) {
		this->s = new Student(a.s->getName(), a.s->getRollno(), a.s->getAge(), a.s->getContact());
		this->count = a.count;
		this->capacity = a.capacity;
		this->c = new Course[capacity];
		this->Marks = new double[capacity];
		this->Attendance = new double[capacity];
		for (int i = 0; i < count; i++) {
			this->c[i] = a.c[i];
			this->Marks[i] = a.Marks[i];
			this->Attendance[i] = a.Attendance[i];
		}
	}
	studentinfoManagament() {
		s = nullptr;
		c = nullptr;
		Marks = nullptr;
		Attendance = nullptr;
		count = 0;
		capacity = 0;
	}
	studentinfoManagament(Student* s1, Course* c1, double* m1, double* Attendance, int count) {
		s = s1;
		c = c1;
		Marks = m1;
		this->Attendance = Attendance;
		this->count = count;
		capacity = 0;
	}
	studentinfoManagament(Student* s1) {
		s = s1;
		this->count = 0;
		capacity = 0;
		c = nullptr;
		Marks = nullptr;
		Attendance = nullptr;
	}
	bool search(string courseId) {
		for (int i = 0; i < count; i++) {
			if (c[i].getCode() == courseId) {
				return true;
			}
		}
		return false;
	}
	void registerCourse(Course& C) {
		if (search(C.getCode()) == true) {
			cout << "\nStudent already enrolled in the course\n";
			return;
		}
		else {
			if (capacity == 0) {
				capacity = 1;
				c = new Course[capacity];
				Marks = new double[capacity];
				Attendance = new double[capacity];
				c[0] = C;
				Marks[0] = 0;
				Attendance[0] = 0;
				count++;

			}
			else if (count < capacity) {
				c[count] = C;
				Marks[count] = 0;
				Attendance[count] = 0;
				count++;
			}
			else {
				capacity = capacity * 2;
				Course* temp1 = new Course[capacity];
				double* temp2 = new double[capacity];
				double* temp3 = new double[capacity];
				for (int i = 0; i < count; i++) {
					temp1[i] = c[i];
					temp2[i] = Marks[i];
					temp3[i] = Attendance[i];
				}
				delete[]c;
				delete[]Marks;
				delete[]Attendance;
				c = temp1;
				Marks = temp2;
				Attendance = temp3;
				c[count] = C;
				Marks[count] = 0;
				Attendance[count] = 0;
				count++;
			}
			cout << "\nStudent registered in the course sucessfully\n";
		}
	}
	string getRollNo() {
		return s->getRollno();
	}
	bool updateMarks(double marks, string code) {
		if (search(code) == false) {
			cout << "\nStudent is not registered in that course\n";
			return false;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (c[i].getCode() == code) {
					Marks[i] = marks;
					cout << "Marks has been updated\n";
					return true;
				}
			}
		}
	}
	void updateAttendance(double A, string code) {
		if (search(code) == false) {
			cout << "\nStudent is not registered in that course\n";
			return;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (c[i].getCode() == code) {
					Attendance[i] = A;
					cout << "Marks has been updated\n";
					return;
				}
			}
		}
	}
	void withdrawCourse(string id) {
		if (search(id) == false) {
			cout << "\nStudent is not enrolled in that course\n";
			return;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (c[i].getCode() == id) {
					for (int j = i; j < count - 1; j++) {
						c[j] = c[j + 1];
					}
					count--;
					cout << "\nCourse has been withdrawn\n";
				}
			}
		}
	}
	void editDetails(string name, int age, string contact) {
		s->setName(name);
		s->setAge(age);
		s->setContact(contact);
	}
	void displayMarks() {
		if (count == 0)
		{
			cout << "\nStudent is not enrolled in any course yet" << endl;
			return;
		}
		cout << "\nStudent Marks in each course are as follows :\n";
		for (int i = 0; i < count; i++) {
			cout << "Marks in : " << c[i].getName() << " are: " << Marks[i] << endl;
		}
	}
	void displayAttendance() {
		if (count == 0)
		{
			cout << "\nStudent is not enrolled in any course yet" << endl;
			return;
		}
		cout << "\nStudent Attendance in each course are as follows :\n";
		for (int i = 0; i < count; i++) {
			cout << "Attendance in : " << c[i].getName() << " is: " << Attendance[i] << "%" << endl;
		}
	}
	void displayAllCourses()
	{
		if (count == 0)
		{
			cout << "\nStudent is not enrolled in any course yet" << endl;
			return;
		}
		for (int i = 0; i < count; i++)
		{
			cout << "Course " << i + 1 << " : " << c[i].getName() << endl;
		}
	}
	~studentinfoManagament() {
		/*delete[]c;
		delete[]Marks;
		delete[]Attendance;*/
	}
};
CourseCatalogue* CourseCatalogue::CC = nullptr;
studentEnrollment* studentEnrollment::se = nullptr;
class System {
private:
	CourseCatalogue* AllCourses = CourseCatalogue::getInstance();
	studentEnrollment* AllStudents = studentEnrollment::getInstance();
	studentinfoManagament* stm;
	static System* ins;
	int count;
	const int capacity = 1000;
	System() {
		int count = 0;
		stm = new studentinfoManagament[capacity];
	}
public:
	static System* getInstance() {
		if (ins == NULL) {
			ins = new System;
		}
		return ins;
	}
	bool addStudent(Student S) {
		bool flag = AllStudents->addStudent(S);
		if (flag == true) {
			studentinfoManagament temp2(&S);
			stm[count++] = temp2;	
		}
		return flag;
	}
	void AddNewCourseToUni(Course c)
	{
		AllCourses->addCourse(c);
	}
	void DisplayAllStudents()
	{
		AllStudents->display();
	}
	void DisplayAllCourses()
	{
		AllCourses->display();
	}
	bool removeStudent(string id) {
		if (count != 0) {
			bool flag = AllStudents->removeStudent(id);
			if (flag) {
				for (int i = 0; i < count; i++) {
					if (stm[i].getRollNo() == id) {
						for (int j = i; j < count - 1; j++) {
							stm[j] = stm[j + 1];
						}
						count--;
						return true;
					}
				}
			}
		}
		else {
			cout << "\nNo Student registred yet\n";
			return false;
		}
	}
	bool editStdDetails(string rollno) {
		bool flag = AllStudents->editDetails(rollno);
		if (flag) {
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					stm[i].editDetails(temp1_name, temp1_age, temp1_contact);
					return true;
				}
			}
		}
		return false;
	}
	bool displayAttendance(string rollno) {
		if (count != 0) {
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					stm[i].displayAttendance();
					return true ;
				}
			}
		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}
	bool markAttendance(string rollno) {
		if (count != 0) {
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					string a;
					double a3;
					cout << "\nEnter the course code for which you want to mark attendance\n";
					cin >> a;
					cout << "\nEnter the attendance percentage\n";
					cin >> a3;
					stm[i].updateAttendance(a3, a);
					return true;
				}
			}
		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}
	void displayMarks(string rollno) {
		if (count != 0) {
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					stm[i].displayMarks();
					return;
				}
			}
		}
		else {
			cout << "\nNo Student enrolled yet\n";
		}
	}
	bool assignMarks(string rollno) {
		if (count != 0) {
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					string a;
					double a3;
					cout << "\nEnter the course code for which you want to assign marks\n";
					cin >> a;
					cout << "\nEnter the marks\n";
					cin >> a3;
					bool flag=stm[i].updateMarks(a3, a);
					return flag;
				}
			}
		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}
	bool enrolledCourses(string rollno) {
		if (count != 0) {
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					stm[i].displayAllCourses();
					return true;
				}
			}
		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}
	bool registerCourse(string rollno, string code) {
		if (count != 0) {
			Course c = AllCourses->search(code);
			if (c.getCode() == "") {
				cout << "\nWrong Course code\n";
					return false;
			}
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					stm[i].registerCourse(c);
					AllCourses->addstudentToaCourse(rollno, c.getCode());
					return true;
				}
			}
		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}
	bool WithdrawCourse(string rollno, string code) {
		if (count != 0) {
			Course c = AllCourses->search(code);
			if (c.getCode() == "") {
				cout << "\nWrong Course code\n";
				return false;
			}
			for (int i = 0; i < count; i++) {
				if (stm[i].getRollNo() == rollno) {
					stm[i].withdrawCourse(c.getCode());
					AllCourses->removestudentfromaCourse(rollno, c.getCode());
					return true;
				}
			}
		}
		else {
			cout << "\nNo Student enrolled yet\n";
			return false;
		}
	}
	~System()
	{
		delete[]stm;
	}
};
System* System::ins = nullptr;
int main() {
    System* S1 = System::getInstance();
    	Student s1("Daud", "22P-9189", 19, "03040179178");
	Student s2("Zaid", "22P-9207", 22, "03012395316");
	Student s3("Hadi", "22P-9222", 21, "03025562352");
	Student s4("Hussam", "22P-9306", 23, "03020189357");
	Course C1("CS-100", "PF", "Faraz Ahmed", 3);
	Course C2("DS-100", "OOP", "Usman Wajid", 2);
	Course C3("CS-90", "English", "Nooreen Shah", 1);
	Course C4("EE-80", "DLD", "Usman Abbasi", 3);
	S1->AddNewCourseToUni(C1);
	S1->AddNewCourseToUni(C2);
	S1->AddNewCourseToUni(C3);
	S1->AddNewCourseToUni(C4);
	S1->addStudent(s1);
	S1->addStudent(s2);
	S1->addStudent(s3);
	S1->addStudent(s4);
	S1->registerCourse("22P-9189", "CS-100");
	S1->registerCourse("22P-9189", "DS-100");
	S1->registerCourse("22P-9189", "CS-90");
	S1->registerCourse("22P-9189", "EE-80");
	S1->registerCourse("22P-9207", "CS-90");
	S1->registerCourse("22P-9207", "DS-100");
	S1->registerCourse("22P-9207", "CS-100");
	S1->registerCourse("22P-9222", "EE-80");
	S1->registerCourse("22P-9222", "CS-90");
	S1->registerCourse("22P-9306", "CS-100");
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
while (true) {
    	cout << "\n\n";
       std::cout << "--------------------------------------------\n";
std::cout << "                Main Menu                   \n";
std::cout << "--------------------------------------------\n";
cout<<endl;
std::cout << "******STUDENT MENU******\n";
std::cout << " 1.  Display Enrolled Students\n";
std::cout << " 2.  Add a Student\n";
std::cout << " 3.  Remove a Student\n";
std::cout << " 4.  Edit Student Details\n";
cout<<endl;
std::cout << "******COURSE MENU******\n";
std::cout << " 5.  Display Available Courses\n";
std::cout << " 6.  Register Student in a Course\n";
std::cout << " 7.  Display Enrolled Courses\n";
std::cout << " 8.  Withdraw from a Course\n";
cout<<endl;
std::cout << "******MARKS MENU******\n";
std::cout << " 9.  Display Student Marks\n";
std::cout << "10.  Assign Marks to a Student\n";
cout<<endl;
std::cout << "******ATTENDENCE MENU******\n";
std::cout << "11.  Display Student Attendance\n";
std::cout << "12.  Mark Student Attendance\n";
std::cout << "13.  Exit\n";
std::cout << "--------------------------------------------\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                S1->DisplayAllStudents();
                break;
            }
            case 2: {
                string name, rollno, contact;
                int age;
                cout << "Enter name: ";
                cin.ignore();
                getline(std::cin, name);
                cout << "Enter rollno: ";
                getline(std::cin, rollno);
                cout << "Enter contact: ";
                getline(std::cin, contact);
                cout << "Enter age: ";
                cin >> age;

                Student newStudent(name, rollno, age, contact);

                bool flag = S1->addStudent(newStudent);
                if (flag)
                    cout << "Student added successfully\n";
                else
                    cout << "Error or Student already exists\n";

                break;
            }
            case 3: {
                string rollno;
                cout << "Enter student roll no: ";
                cin.ignore();
                getline(std::cin, rollno);

                bool flag = S1->removeStudent(rollno);
                if (flag)
                    cout << "Student removed successfully\n";
                else
                    cout << "Wrong credentials or student not found\n";

                break;
            }
          case 4: {
        // Code for editing student details
        // Example: S1->editStdDetails("22L-6822");
        {
            string rollno;
           cout << "Enter student roll no: ";
            cin.ignore();
            getline(std::cin, rollno);

            bool flag = S1->editStdDetails(rollno);
            if (flag)
                cout << "Student details updated successfully\n";
            else
                cout << "Wrong credentials or student not found\n";
        }
        break;
    }

    case 5: {
        // Code for displaying available courses
        // Example: S1->DisplayAllCourses();
        S1->DisplayAllCourses();
        break;
    }

case 6: {
    // Code for registering a student in a course

    {
       string rollno, code;
        cout << "Enter student roll no: ";
       cin.ignore();
        getline(std::cin, rollno);
        cout << "Enter course code: ";
       getline(std::cin, code);

        bool flag = S1->registerCourse(rollno, code);
        if (flag)
            cout << "Student registered in the course successfully\n";
        else
            cout << "Wrong credentials or course not found\n";
    }
    break;
}


    case 11: {
        // Code for displaying student attendance
        // Example: S1->displayAttendance("22L-6822");
        {
            string rollno;
            cout << "Enter student roll no: ";
            cin.ignore();
            getline(std::cin, rollno);

            bool flag = S1->displayAttendance(rollno);
            if (!flag)
                cout << "Wrong credentials or student not found\n";
        }
        break;
    }
case 12: {
    // Code for marking student attendance
    // Example: S1->markAttendance("22L-6822");
    {
        string rollno;
        cout << "Enter student roll no: ";
        cin.ignore();
        getline(std::cin, rollno);

        bool flag = S1->markAttendance(rollno);
        if (!flag)
            cout << "Wrong credentials or student not found\n";
    }
    break;
}

case 9: {
    // Code for displaying student marks
    // Example: S1->displayMarks("22L-6822");
    {
        string rollno;
        cout << "Enter student roll no: ";
        cin.ignore();
        getline(std::cin, rollno);

        S1->displayMarks(rollno);
    }
    break;
}

case 10: {
    // Code for assigning marks to a student
    // Example: S1->assignMarks("22L-6822");
    {
       string rollno;
       cout << "Enter student roll no: ";
        cin.ignore();
        getline(std::cin, rollno);

        bool flag = S1->assignMarks(rollno);
        if (!flag)
            cout << "Wrong credentials or student not found\n";
    }
    break;
}

case 7: {
    // Code for displaying enrolled courses
    // Example: S1->enrolledCourses("22L-6822");
    {
        string rollno;
        cout << "Enter student roll no: ";
        cin.ignore();
        getline(std::cin, rollno);

        bool flag = S1->enrolledCourses(rollno);
        if (!flag)
            cout << "Wrong credentials or student not found\n";
    }
    break;
}

case 8: {
// Code for withdrawing from a course
// Example: S1->WithdrawCourse("22L-6822");
{
string rollno, code;
cout << "Enter student roll no: ";
cin.ignore();
getline(std::cin, rollno);
cout << "Enter course code: ";
getline(std::cin, code);
    bool flag = S1->WithdrawCourse(rollno, code);
    if (flag)
        cout << "Student withdrawn from the course successfully\n";
    else
        cout << "Wrong credentials or course not found\n";
}
break;
}

case 13: {
// Exit the program
cout << "Project By DEV BEASTS\n";
return 0;
}

default:
cout << "Invalid choice\n";
}
}
return 0;
}
