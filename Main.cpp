//Author: Nathan Zou
//Second part of Linked Lists using Node.o and Node.h from Oria W
//Done with the help of Chris Zou and Stefan Ene
//Status: Work In Progress
//Date: 1/30/22

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

//Functions
void ADD(Node*& head, Node* prev, Student* student);
void PRINT(Node* head);
void AVERAGE(Node* head, int counter);

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
        if (strcmp(input, "Add") == 0 || strcmp(input, "ADD") == 0) { //If input is add
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
            ADD(head, NULL, addStudent);
            cout << "Successfully Added Student" << endl;
            cout << "Number of Nodes: " << nodeCount << endl;
        }
        else if (strcmp(input, "Print") == 0 || strcmp(input, "PRINT") == 0) { //If input is print
            PRINT(head);
        }
        else if (strcmp(input, "Delete") == 0 || strcmp(input, "DELETE") == 0) { //If input is delete
            cout << "Delete" << endl;
            //nodeCount--;
            //cout << "Number of Nodes: " << nodeCount << endl;
        }
        else if (strcmp(input, "Average") == 0 || strcmp(input, "AVERAGE") == 0) { //If input is average
            AVERAGE(head, nodeCount);
        }
        else if (strcmp(input, "Quit") == 0 || strcmp(input, "QUIT") == 0) { //If input is quit
            running = false;
            cout << endl << "Quitting program." << endl;
        }
        else { //Invalid inputs
            cout << "Invalid command, try again." << endl;
        }
    }
    return 0;
}

//Add function, done with the help of Chris Zou
void ADD(Node* &head, Node* prev, Student* student) {
    Student* oldStudent = new Student();
    Node* tempNode;
    Node* tempPrev;
    Node* tempHead;
    if (head == NULL) { //Add to end of LL
        //cout << *(student->getID()) << " Added to end of LL" << endl; 
        tempNode = new Node(student, NULL); 
        if (prev == NULL) {
            head = tempNode;
            return;
        }
        //prev != NULL
        else {
            prev->setNext(tempNode);
        }
    }
    //head != NULL
    else { //Add new node before the node that is pointed to by the head variable
        oldStudent = head->getStudent();
        tempPrev = head;
        tempHead = head->getNext();
        if (*(oldStudent->getID()) < *(student->getID())) {
            ADD(tempHead, tempPrev, student);
        }
        //*(oldStudent->getID()) > *(student->getID())
        else {
            //cout << *(student->getID()) << " Added to beginning of head" << endl;
            tempNode = new Node(student, prev);
            tempNode->setNext(head);
            if (prev == NULL) {
                head = tempNode;
            }
            //prev != NULL
            else {
                prev->setNext(tempNode);
                tempNode->setNext(head);
            }
        }
    }
}

//Print function
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

//Average fucntion, help from Stefan Ene
void AVERAGE(Node* head, int nodeCount) {
    Node* current = head;
    float total = 0;
    if (head == NULL) {
        cout << endl << "Cannot average 0 students GPA\'s, add students first." << endl;
        return;
    }
    else {
        total += *current->getStudent()->getGPA();
        while (current->getNext() != NULL) {
            total += *current->getNext()->getStudent()->getGPA();
            current = current->getNext();
        }
    }
    cout << endl << "Average GPA: " << fixed << setprecision(2) << (total / nodeCount) << endl;
}
