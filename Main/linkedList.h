#pragma once
#include "Node.h"

struct linkedList {
    Node* head; 
    Node* end;

    linkedList();

    void Insert(Node* dl);
    void push_back(Node* dl);
    void pop();
    void erase();
    void Print();
    void clearList();
    void upDate(int id);

};

