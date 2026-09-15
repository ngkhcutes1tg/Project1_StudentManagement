#include <iostream>
#include <cstring>

struct student {
    int id;
    double gpa;
    std::string name;
};

struct Node {
   student data;
   Node* next; 
};

Node* head;

void Insert(int i, double g, std::string n) {
    Node* temp = new Node;
    temp->next = nullptr;
    temp->data.id = i;
    temp->data.gpa = g;
    temp->data.name = n;
    if(head == nullptr) {
        head = temp;
        return;
    }
    Node* temp2 = head;
    while(temp2->next != nullptr) {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

void Print() {
    Node* temp = head; 
    int i = 1;
    std::cout << "-----In thong tin sinh vien-----\n";
    while(temp != nullptr) {
        std::cout << "Thong tin ve sinh vien thu " << i << ": \n"; 
        std::cout << "Ma SV: " << temp->data.id << "\n" 
        << "Ho va ten: " << temp->data.name << "\n" 
        << "GPA: " << temp->data.gpa << "\n";
        temp = temp->next;
        i++;
    }
}

void clearList() {
    Node* temp = head;
    while(temp != nullptr) {
        Node* nextnode = temp->next;
        delete temp;
        temp = nextnode;
    }
    head = nullptr;
}

int main() {
    head = nullptr;
    int n;
    std::cout << "Nhap so luong sinh vien: ";
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cout << "-----Nhap thong tin sinh vien thu " << i + 1 << "-----\n";
        int id;
        double gpa;
        std::string name;
        std::cout << "Nhap ID: ";
        std::cin >> id;
        std::cout << "Nhap ten: ";
        std::cin.ignore();
        getline(std::cin, name);
        std::cout << "Nhap GPA: ";
        std::cin >> gpa;
        Insert(id, gpa, name);
    }
    Print();
    clearList();
}