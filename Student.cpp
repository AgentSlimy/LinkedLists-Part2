//Author: Nathan Zou
//Part of Linked Lists 2

#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student() {

}

Student::~Student() { //Destructor
	delete& firstName;
	delete& lastName;
	delete& ID;
	delete& GPA;
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
