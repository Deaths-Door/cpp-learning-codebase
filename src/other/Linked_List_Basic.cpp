#include <iostream>
using namespace std;

class Node {
    public: int data; Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
    public:Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    // iterates through the list from the end so prints in reverse order
    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
};

int main(){

    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    list.print();
    return 0;
}