#include "roster.h"

void Roster::add(int i, string studentID, string firstName, string lastName, string email, int age, int course1, int course2, int course3, DegreeProgram dProgram)
//void gets called by parse and populates the array at index 'i' with a student object by calling the constructor
{
		classRosterArray[i] = new Student(studentID, firstName, lastName, email, age, course1, course2, course3, dProgram);
}
void Roster::remove(string studentID)
{
	//sets a boolean to track if studentID is found
	bool studentFound = false;

	//following for loop checks for the studentID to match, deletes and sets that position to nullptr
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;

			//nested for loop shifts the positions to the left
			for (int j = i; j < 4; j++) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			classRosterArray[4] = nullptr;
			studentFound = true; 
			break;
		}
	}
	
	//if the ID isnt found the following will print
	if (!studentFound) {
		cout << "The student with ID: " << studentID << " was not found." << endl;
	}
}

Roster::~Roster()
{
}
void Roster::parse(string data, int i)
{
		//parsing data via the find in built method using commas and setting the variables that will be used to call add
		size_t rhs = data.find(",");
		string studentID = data.substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = data.find(",", lhs);
		string firstName = data.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		string lastName = data.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		string email = data.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		int age = stol(data.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		int course1 = stol(data.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		int course2 = stol(data.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		int course3 = stol(data.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		string degreeProgram = data.substr(lhs, rhs - lhs);

		DegreeProgram dProgram = DegreeProgram::NETWORK;
		if (degreeProgram == "NETWORK") {
			dProgram = DegreeProgram::NETWORK;
		}

		else if (degreeProgram == "SECURITY") {
			dProgram = DegreeProgram::SECURITY;
		}
		else if (degreeProgram == "SOFTWARE") {
			dProgram = DegreeProgram::SOFTWARE;
		}

		//calls add with the additional i parameter to help with index positioning
		add(i, studentID, firstName, lastName, email, age, course1, course2, course3, dProgram);
}

void Roster::printAll(int n) {

	//calls print method for every position in the array, 'n' will help us adjust our loop for when called after remove has been called
	for(int i = 0 ; i < 5-n; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{

	//iterate through the array until studentID matches
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int* daysInCourses = classRosterArray[i]->getDaysInCourses();

			//calculate average by looping through daysInCourses array and continously adding each position up then dividing by 3
			int sum = 0;
			for (int j = 0; j < 3; j++) {
				sum += daysInCourses[j];
			}
			int average = sum / 3;

			cout << "Student ID: " << studentID << ", average days in course is: " << average << endl;
		}
	}
}
void Roster::printInvalidEmail()
{
	cout << endl << "Displaying invalid emails:" << endl << endl;

	//bool to track if theres an invalid email
	bool foundInvalid = false;

	//iterate through the array for the email values
	for (int i = 0; i < 5; i++) {
		string email = classRosterArray[i]->getEmail();

		
		//check there are no spaces
		bool isValid = true;
		for (char c : email) {
			if (c == ' ') {
				isValid = false;
				break;
				//break if space is found
			}
		}

		//if no spaces now check if there is a @ and .
		size_t atPos = email.find('@');
		size_t dotPos = email.find('.');
		if (isValid && (atPos == string::npos || dotPos == string::npos)) {
			isValid = false;
		}

		//if email is invalid print it
		if (!isValid) {
			foundInvalid = true;
			cout << email << " - is invalid." << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{

	//iterate through the array and print any positions that match the enum value
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}
