#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>
#include "Student.h"
#include "linkedList.h"
#include "Node.h"

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
    A.Print();
    int x = n;
    while(true) {
        int k;
        std::cout << "-----Chon chuc nang muon su dung-----\n"
        << "1. Them 1 node vao cuoi ds\n" 
        << "2. Them 1 node vao dau ds\n"
        << "3. In ds\n"
        << "4. Xoa 1 node cuoi ds\n"
        << "5. Xoa 1 node dau ds\n" 
        << "6. Cap nhat ten va diem\n"
        << "7. Thoat\n";
        std::cout << "Lua chon cua ban: ";
        std::cin >> k;
        if(k == 7) {
            std::cout << "Thoat chuong trinh!\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            break;
        }
        else {
            if(k == 1 || k == 2) {
                std::cout << "-----Nhap thong tin sinh vien thu "; 
                if(k == 1)
                    std::cout << x + 1; 
                else std::cout << 1;
                std::cout << "-----\n";
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
                std::this_thread::sleep_for(std::chrono::milliseconds(2300));
                std::cout << "Them thanh cong!\n";
            }
            else if(k == 4) {
                A.pop();
                x--;
                std::this_thread::sleep_for(std::chrono::milliseconds(2300));
                std::cout << "Xoa thanh cong!\n";
            }
            else if(k == 5) {
                A.erase();
                x--; 
                std::this_thread::sleep_for(std::chrono::milliseconds(2300));
                std::cout << "Xoa thanh cong!\n";   
            } 
            else if(k == 3) {
                A.Print();
            } 
            else {
                int m;
                std::cout << "Nhap ID can cap nhat du lieu: ";
                std::cin >> m;
                A.upDate(m);
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    A.clearList();
}