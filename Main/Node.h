#pragma once
#include "Student.h"

struct Node {
    student data;
    Node *next, *prev;
    // Node(student data) : data(data) {}

    Node() {}

    Node(int i, double g, std::string n) {
        data.id = i;
        data.gpa = g;
        data.name = n;
    }
};