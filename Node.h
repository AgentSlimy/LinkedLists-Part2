/*
Node with Student pointer and pointer to next node; can be used for one-way
linked lists.
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Student.h"

class Node {
  public:
    Node(); // Default constructor
    Node(Student*, Node*); // Constructor given a Student*
    ~Node(); // Destructor
    Node* getNext(); // Get pointer to next node
    Student* getStudent(); // Get pointer to this node's student
    void setNext(Node*); // Set next to point to given node

  protected:
    Student* student;
    Node* next;
};

#endif
