//Author: Nathan Zou
//Second part of Linked Lists using Node.o and Node.h from Oria W
//Status: Work In Progress
//Date: 1/30/22

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

void ADD (Node* &head, Node* &prev, Student* student);

int main() {
  bool running = true;
  char input[15];
  Node* head = NULL; //first node
  int nodeCount = 0; //number of nodes, duh

  //Start
  cout << "Linked Lists, the Sequel, ft Oria W.\'s Code" << endl;
  cout << "--------------------------------------------" << endl;
  while (running == true) {
    //Commands
    cout << endl << "Add, Print, Delete, Average, and Quit" << endl;
    cout << "Input command of choice: " << endl;
    cin.get(input, 15);
    cin.clear();
    cin.ignore(10000, '\n');

    //Add
    if(strcmp(input, "Add") == 0 || strcmp(input, "ADD") == 0) {
      nodeCount++;
      Student* addStudent = new Student();
      cout << "Students First Name: " << endl;
      cin.get(addStudent->getFirstName(), 20);
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Students Last Name: " << endl;
      cin.get(addStudent->getLastName(), 20);
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Students ID Number: " << endl;
      cin >> *addStudent->getID();
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Students GPA: " << endl;
      cin >> *addStudent->getGPA();
      cin.clear();
      cin.ignore(10000, '\n');
      ADD(head, head, addStudent);
      cout << "Successfully Added Student" << endl;
    } //end of add
    



    
  } //end of "while (running = true)"    
} //end of main
