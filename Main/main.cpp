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
   Node* prev;
   Node() {
    data.id = 0;
    data.gpa = 0.0;
    data.name = "";
   }
   Node(int i, double g, std::string n) {
    data.id = i;
    data.gpa = g;
    data.name = n;
   } 
};

struct linkedList {

    Node* head = nullptr;
    Node* end = nullptr;
    
    void Insert(Node* dl) {
        dl->next = nullptr;
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

    void push_back(Node* dl) {
        dl->next = nullptr;
        dl->prev = nullptr;

        if(end == nullptr) {
            end = dl;
            head = dl;
            return;
        }
        end->next = dl;
        dl->prev = end;
        end = dl;
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

    void pop() {
        Node* temp2 = end;
        Node* temp = end->prev;
        temp->next = nullptr;
        end = temp;
        delete temp2; 
    }

    void erase() {
        Node* temp = head;
        head = head->next;
        delete temp; 
    }
};

int main() {
    int n;
    std::cout << "Nhap so luong sinh vien: ";
    std::cin >> n;
    linkedList A;
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
        Node* H = new Node(id, gpa, name);
        Node* E = new Node(id, gpa, name);
        A.Insert(H);
        A.push_back(E);
        A.Print();
        A.clearList();
    }
}