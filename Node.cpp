/*
Node with Student pointer and pointer to next node; can be used for one-way
linked lists.
*/

#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

// Default constructor
Node::Node() {
  student = new Student;
  next = NULL;
  student->setInfo();
}

// Constructor given a Student*
Node::Node(Student* newStudent, Node* newNext) {
  student = newStudent;
  next = newNext;
}

// Destructor
Node::~Node() {
  delete student; // assuming the Student class has a rigorous destructor
  // The destructor does NOT find the previous Node and point its next to a new
  // spot - that is up to the function that deletes listings.
}

// Get pointer to next node
Node* Node::getNext() {
  return next;
}

// Get pointer to this node's student
Student* Node::getStudent() {
  return student;
}

// Set next to point to given node
void Node::setNext(Node* newNext) {
  next = newNext;
}
