#pragma once
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
/*
To Create .O file run this command :
    cd C:\MinGW\bin
    g++ -c "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\LinkedList.cpp" -o "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\LinkedList.o"

To Link with main.cpp file :
    g++ "main.cpp directory" "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\LinkedList.o" -o .exe file name

To Link with its test file :
    g++ "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\mains\LinkedListMain.cpp" "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\LinkedList.o" -o linkedlistmain
*/
#include <memory>
#include <stdexcept>

namespace deathsdoor::nodes {
    template<typename T>
    class LinkedListNode{
        public : using linkedlistNode = std::unique_ptr<LinkedListNode<T>>;
        private: T _value; linkedlistNode _next = nullptr;
        public:
            LinkedListNode(const T value) noexcept : _value(value) {}
            LinkedListNode(const T value,const linkedlistNode node) noexcept : _value(value), _next(std::move(node)) {}

            T getValue() const noexcept{
                return this->_value;
            }
            linkedlistNode& getNext() const noexcept{
                return this->_next;
            }

            bool isNextNull() const noexcept{
                return this->_next == nullptr;
            }
            bool isNextNotNull() const noexcept{
                return this->_next != nullptr;
            }

            friend std::ostream& operator<<(std::ostream& os, const LinkedListNode<T>& node) noexcept{
                os << node._value;
                return os;
            }
    };
    template<typename T>
    class LinkedList{
        private:
            typename LinkedListNode<T>::linkedlistNode head;
            typename LinkedListNode<T>::linkedlistNode tail;
            int length = 1;
        public:
            LinkedList(const LinkedListNode<T> node) noexcept;

            typename LinkedListNode<T>::linkedlistNode& getHead() const noexcept;
            typename LinkedListNode<T>::linkedlistNode& getTail() const noexcept;
            int getLength() const noexcept;

            bool isEmpty() const noexcept;

            void insert(const T value) noexcept;
            void insert(LinkedListNode<T> node) noexcept;

            void insertAt(const T value,int index);
            void insertAt(LinkedListNode<T> value,int index);

            void insertAtHead(const T value) noexcept;
            void insertAtHead(LinkedListNode<T> value) noexcept;


            void deleteNode(const T value) noexcept;
            void deleteNodeAtPosition(const int position) noexcept;
            void deleteAlle() noexcept;

            friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) noexcept{  
              //  for (std::unique_ptr<LinkedList<T>> current = std::move(head); current != nullptr; current = std::move(current->next)) {
                 //   os << value << " ";
               // }
                return os;
            }
    };
}

#endif //LINKEDLIST_HPP
