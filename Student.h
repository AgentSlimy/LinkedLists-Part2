//Author: Nathan Zou
//Part of Linked Lists 2

#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student {
public:
	Student();
	~Student(); //Destructor
	//Getters
	char* getFirstName();
	char* getLastName();
	int* getID();
	float* getGPA();
	void setInfo();
private:
	char firstName[20];
	char lastName[20];
	int ID;
	float GPA;
};
#endif
