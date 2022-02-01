//Author: Nathan Zou
//Part of Linked Lists 2

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"

using namespace std;

Student::Student() {

}

Student::~Student() { //Destructor

}

//Getters
char* Student::getFirstName() {
	return firstName;
}

char* Student::getLastName() {
	return lastName;
}

int* Student::getID() {
	return &ID;
}

float* Student::getGPA() {
	return &GPA;
}

void Student::setInfo() {

}

void Student::print() {
	cout << "Name: " << getFirstName() << " " << getLastName();
	cout << " ID: " << ID << " GPA: " << fixed << setprecision(2) << GPA << endl;
}
