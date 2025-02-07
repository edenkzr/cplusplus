#pragma once
#include "student.h"

//create the Roster class
class Roster {

public:

	//set up array of pointers for the student objects
	Student* classRosterArray[5];

	//destructor
	~Roster();

	//roster method declarations
	void parse(string data, int i);

	void add(int i, string studentID, string firstName, string lastName, string email, int age, int course1, int course2, int course3, DegreeProgram dProgram);

	void remove(string studentID);

	void printAll(int n);

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmail();

	void printByDegreeProgram(DegreeProgram degreeProgram);

};