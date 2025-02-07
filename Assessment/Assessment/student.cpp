#include "student.h"

//definitions for accessors
std::string Student::getStudentID()
{
	return std::string(studentID);
}

std::string Student::getFirstName()
{
	return std::string(firstName);
}

std::string Student::getLastName()
{
	return std::string(lastName);
}

std::string Student::getEmail()
{
	return std::string(email);
}

int Student::getAge()
{
	return int(age);
}

int* Student::getDaysInCourses()
{
	return daysInCourses;
}

DegreeProgram Student::getDegreeProgram()
{
	return DegreeProgram(degreeProgram);
}


//definitions for the setters
void Student::setStudentID(string id)
{
	studentID = id;
}

void Student::setFirstName(string fName)
{
	firstName = fName;
}

void Student::setLastName(string lName)
{
	lastName = lName;
}

void Student::setEmail(string eMail)
{
	email = eMail;
}

void Student::setAge(int sAge)
{
	age = sAge;
}

void Student::setDaysInCourses(int course1, int course2, int course3)
{
	daysInCourses[0] = course1;
	daysInCourses[1] = course2;
	daysInCourses[2] = course3;
}

void Student::setDegreeProgram(DegreeProgram dProgram)
{
	degreeProgram = dProgram;
}

//definition for the print method
void Student::print()
{

	//set up if else branches to fill in degreeProgramString with the corresponding value depending on what enum was passed
	string degreeProgramString = " ";

	if (degreeProgram == 0) {

		degreeProgramString = "SECURITY";

	}
	else if(degreeProgram == 1) {

		degreeProgramString = "NETWORK";

	}
	else {

		degreeProgramString = "SOFTWARE";

	}

	//print out formatting
	cout << studentID + "\tFirst Name: " + firstName + "\tLast Name: " + lastName + "\tEmail: " + email + "\tAge: " << age << 
		"\tdaysInCourse: {" << daysInCourses[0] << "," << daysInCourses[1] << "," << daysInCourses[2] << "}    DegreeProgram: " << degreeProgramString << endl;
}
