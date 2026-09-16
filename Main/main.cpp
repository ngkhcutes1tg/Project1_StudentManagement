#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

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
            std::cout << "***Thong tin ve sinh vien thu " << i << ": \n"; 
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
        A.push_back(H);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(n * 1500));
    A.Print();
    int x = n;
    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        int k;
        std::cout << "-----Chon chuc nang muon su dung-----\n"
        << "1. Them 1 node vao cuoi ds\n" 
        << "2. Them 1 node vao dau ds\n"
        << "3. In ds\n"
        << "4. Xoa 1 node cuoi ds\n"
        << "5. Xoa 1 node dau ds\n" 
        << "6. Thoat\n";
        std::cout << "Lua chon cua ban: ";
        std::cin >> k;
        if(k == 6) {
            break;
        }
        else {
            if(k == 1 || k == 2) {
                std::cout << "-----Nhap thong tin sinh vien thu " << x + 1 << "-----\n";
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
                if(k == 1)  
                    A.push_back(H);
                else A.Insert(H);
                x++;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                std::cout << "Them thanh cong!\n";
            }
            else if(k == 4) {
                A.pop();
                x--;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                std::cout << "Xoa thanh cong!\n";
            }
            else if(k == 5) {
                A.erase();
                x--; 
                std::this_thread::sleep_for(std::chrono::seconds(2));
                std::cout << "Xoa thanh cong!\n";   
            } 
            else {
                A.Print();
                std::this_thread::sleep_for(std::chrono::milliseconds(x * 1500));
                // char t;
                // std::cout << "Bam y de tiep tuc n de dung lai!\n";
                // std::cin >> t;
                // if(t == 'n' || t == 'N') {
                //     break;
                // }
            } 
        }
    }
    A.clearList();
}