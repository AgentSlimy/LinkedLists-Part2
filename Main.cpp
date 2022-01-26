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

void ADD (Node* &head, Node* prev, Student* student);
void PRINT (Node* head);

int main() {
  bool running = true;
  char input[15];
  Node* head = NULL; //first node
  int nodeCount = 0; //number of nodes, duh

  //Beginning of code
  cout << "Linked Lists, the Sequel, ft Oria W.\'s Code" << endl;
  cout << "--------------------------------------------" << endl;
  while (running == true) {
    //Start prompt
    cout << endl << "Add, Print, Delete, Average, and Quit" << endl;
    cout << "Input command of choice: " << endl;
    cin.get(input, 15);
    cin.clear();
    cin.ignore(10000, '\n');

    //Commands
    if(strcmp(input, "Add") == 0 || strcmp(input, "ADD") == 0) { //If input is add
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
    }
    else if(strcmp(input, "Print") == 0 || strcmp(input, "PRINT") == 0) { //If input is print
      cout << "Print" << endl;
    }
    else if(strcmp(input, "Delete") == 0 || strcmp(input, "DELETE") == 0) { //If input is delete
      cout << "Delete" << endl;
    }
    else if(strcmp(input, "Average") == 0 || strcmp(input, "AVERAGE") == 0) { //If input is average
      cout << "Average" << endl;
    }
    else if(strcmp(input, "Quit") == 0 || strcmp(input, "QUIT") == 0) { //If input is quit
      running = false;
      cout << endl << "Quitting program." << endl;
    }
    else { //Invalid inputs
      cout << "Invalid command, try again." << endl;
    }


    
  } //end of "while (running = true)"    
} //end of main


void ADD(Node* &head, Node* prev, Student* student) {
  if (head == NULL) {
    head = new Node(student);
  }
  else if (prev->getNext() == NULL) {
    if (*student->getID() > *head->getStudent()->getID()) {
      Node* newNode = new Node(student);
      prev->setNext(newNode);
    }
    else {
      Node* temp = new Node(head->getStudent());
      head = new Node(student);
      head->setNext(temp);
    }
  }
  else if (*student->getID() < *head->getStudent()->getID()) {
    Node* temp = new Node(head->getStudent());
    temp->setNext(head->getNext());
    head = new Node(student);
    head->setNext(temp);
  }
  else if (*student->getID() < *prev->getStudent()->getID()) {
    Node* newNode = new Node(student);
    newNode->setNext(prev->getNext());
    prev->setNext(newNode);
  }
  else {
    ADD(head, prev->getNext(), student);
  }
}

void PRINT(Node* head) {
  Node* currentNode = head;
  if (currentNode == NULL) {
    cout << endl << "List is empty, try adding some students first." << endl;
  }
  else {
    cout << endl << "Printing students:" << endl;
    while (currentNode != NULL) {
      cout << currentNode->getStudent()->getFirstName() << " ";
      cout << currentNode->getStudent()->getLastName() << ", ";
      cout << "ID: " << *currentNode->getStudent()->getID() << ", ";
      cout << "GPA: " << fixed << setprecision(2) << *currentNode->getStudent()->getGPA() << endl;
      currentNode = currentNode->getNext();
    }
    cout << endl;
  }
}
