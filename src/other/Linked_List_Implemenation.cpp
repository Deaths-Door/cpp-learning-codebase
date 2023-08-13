#include <iostream>
using namespace std;

class Node{
    public
        int data; 
        Node* next;
    Node(int data,Node* next) : data(data),next(next) { }
};

class LinkedList{
    public : Node* head;
    LinkedList() : head(nullptr) {}

    void insert(int data){
        Node* node = new Node(data,head);
        head = node;
    }

    void deleteAll(){
        Node* current = head;
        while(current){
            Node* next = current -> next;
            delete current;
            current = next;
        }
        head = nullptr
    }

    void deleteLast(){
        // Return if the list is empty
        if (!head) return;  

        // If there's only one element in the list, delete it and set head to nullptr
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        // Iterate through the list until you reach the second-to-last element
        Node* current = head;
        while(current->next->next){
            current = current -> next;
        }

        //Delete it
        delete current->next;
        current->next = nullptr;
    }
    
    bool in(int value){
        Node* current = head;
        while(current){
            if(current->data == value) return true;
            current = current -> next;
        }
        return false;
    }

    bool in(Node* current, int value){
        Node* current = head;
        while(current){
            if(current->data == value) return true;
            current = current -> next;
        }
        return false;
    }
}

int main(){
    LinkedList list;
    list.insert(1);
    return 0;
}