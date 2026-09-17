#include <iostream>
#include "linkedList.h"
#include <chrono>
#include <thread>

linkedList::linkedList() {
    head = nullptr;
    end = nullptr;
}

void linkedList::Insert(Node* dl) {
    dl->prev = nullptr;
    if(head == nullptr) {
        head = dl;
        end = dl;
        return;
    }
    dl->next = head;
    head->prev = dl;
    head = dl;
}

void linkedList::push_back(Node* dl) {
    dl->next = nullptr;
    if(end == nullptr) {
        head = dl;
        end = dl;
        return;
    }
    end->next = dl;
    dl->prev = end;
    end = dl;
}

void linkedList::pop() {
    if(end == nullptr) return;

    Node* temp = end;
    end = end->prev;
    if(end != nullptr) {
        end->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete temp;
}

void linkedList::erase() {
    if(head == nullptr) return;

    Node* temp = head;
    head = head->next;
    if(head != nullptr) {
       head->prev = nullptr; 
    }
    else {
        end = nullptr;
    }
    delete temp;
}
void linkedList::Print() {
    Node* temp = head; 
    int i = 1;
    std::cout << "-----In thong tin sinh vien-----\n";
    while(temp != nullptr) {
        std::cout << "***Thong tin ve sinh vien thu " << i << ": \n"; 
        std::cout << "Ma SV: " << temp->data.id << "\n" 
        << "Ho va ten: " << temp->data.name << "\n" 
        << "GPA: " << temp->data.gpa << "\n";
        temp = temp->next;
        i++;
        std::this_thread::sleep_for(std::chrono::milliseconds(2300));
    }
}

void linkedList::clearList() {
    Node* temp = head;
    while(temp != nullptr) {
        Node* temp2 = temp->next;
        delete temp;
        temp = temp2;    
    }
    head = nullptr;
} 

void linkedList::upDate(int id) {
    Node* temp = head;
    Node* correct = new Node();
    correct = nullptr;
    while(temp != nullptr) {
        if(temp->data.id == id) {
            correct = temp;            
            break;
        }
        temp = temp->next;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2300));
    if(correct == nullptr) {
        std::cout << "Khong tim thay id nay!\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        return;
    }
    else {
        std::cout << "Thong tin sv ID " << correct->data.id << ": \n";
        std::cout << "Ho va ten: " << correct->data.name << "\nGPA: " << correct->data.gpa << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        int i;
        std::cout << "Cap nhat ID: ";
        std::cin >> i;
        std::string n;
        double g;
        std::cin.ignore();
        std::cout << "Cap nhat ten: ";
        std::getline(std::cin, n);
        std::cout << "Cap nhat GPA: ";
        std::cin >> g;
        correct->data.gpa = g;
        correct->data.name = n;
        std::this_thread::sleep_for(std::chrono::milliseconds(2300));
        std::cout << "Cap nhat thanh cong!\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}