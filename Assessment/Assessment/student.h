#pragma once
#include "degree.h"
#include <iostream>
using namespace std;

//create the Student class
class Student {

//member variables can only be accessed inside the class
private:

    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourses[3];
    DegreeProgram degreeProgram;


public:

    //constructor with parameters
    Student(const std::string& id, const std::string& fName, const std::string& lName, const std::string& eMail, int sAge, int course1, int course2, int course3, const DegreeProgram& dProgram)
    {
        studentID = id;
        firstName = fName;
        lastName = lName;
        email = eMail;
        age = sAge;
        daysInCourses[0] = course1;
        daysInCourses[1] = course2;
        daysInCourses[2] = course3;
        degreeProgram = dProgram;
    }

    //accessors
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDaysInCourses();
    DegreeProgram getDegreeProgram();


    //setters
    void setStudentID(string id);
    void setFirstName(string fName);
    void setLastName(string lName);
    void setEmail(string eMail);
    void setAge(int sAge);
    void setDaysInCourses(int course1, int course2, int course3);
    void setDegreeProgram(DegreeProgram dProgram);

    //print method for the students data
    void print();
};


