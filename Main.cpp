//Author: Nathan Zou
//Second part of Linked Lists using Node.o and Node.h from Oria W
//Done with the help of Chris Zou, Stefan Ene, and Kyle Zhou
//Status: Completed, Last modified 1/29/22
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
void DELETE(Node*& head, Node* current, Node* prev, int ID);

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
            int ID;
            nodeCount--;
            cout << "What is the ID you want to delete?" << endl;
            cin >> ID;
            cin.clear();
            cin.ignore(10000, '\n');
            DELETE(head, head, NULL, ID);
            cout << "Number of Nodes: " << nodeCount << endl;
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
    if (head == NULL) { //No nodes in list
        cout << endl << "Cannot average 0 students GPA\'s, add students first." << endl;
        return;
    }
    else {
        total += *current->getStudent()->getGPA(); //Start with first node/student
        while (current->getNext() != NULL) { //Keep adding GPAs
            total += *current->getNext()->getStudent()->getGPA();
            current = current->getNext();
        }
    }
    cout << endl << "Average GPA: " << fixed << setprecision(2) << (total / nodeCount) << endl;
}

//Delete function, help from Kyle Zhou and Chris Zou
void DELETE(Node* &head, Node* current, Node* prev, int ID) {
    if (head == NULL) {
        return;
    }
    if (*current->getStudent()->getID() == ID) {
        if (prev == NULL) {
            head = current->getNext();
        }
        else {
            prev->setNext(current->getNext());
        }
        delete current;
        return;
    }
    if (current->getNext() != NULL) {
        DELETE(head, current->getNext(), current, ID);
    }
}
