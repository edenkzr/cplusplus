#include "roster.h"

int main()
{
	Roster roster;

	const std::string studentData[] =

	{ 
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
	"A5,Diego,Cuadros,cuadd.eden@gmail.com,29,20,30,40,SOFTWARE" };

	cout << "C867 - Scripting & Programming: Applications" << endl << "Language: C++" << endl << "StudentID: 011746822" << endl << "Name: Diego Cuadros" << endl << endl;

	cout << "Displaying all students:" << endl;

	//the only real code in the main is this, I initialize the i outside of the for loop so that I can continue to pass it into the parse and add methods later on for array positioning
	int i = 0;
	for (i; i < 5; i++) {
		roster.parse(studentData[i], i);
	}
	roster.printAll(0);
	roster.printInvalidEmail();

	cout << endl;

	roster.printAverageDaysInCourse("A1");
	roster.printAverageDaysInCourse("A2");
	roster.printAverageDaysInCourse("A3");
	roster.printAverageDaysInCourse("A4");
	roster.printAverageDaysInCourse("A5");

	cout << endl;
	cout << "Showing students in degree program: SOFTWARE" << endl << endl;

	roster.printByDegreeProgram(SOFTWARE);

	cout << endl;
	cout << "Removing A3:" << endl << endl;

	roster.remove("A3");
	roster.printAll(1);
	
	cout << endl;
	cout << "Removing A3 again:" << endl << endl;

	roster.remove("A3");

	cout << "DONE.";
	//hope I did well thank you for your time!

}
