#include <iostream>
#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\LinkedList.hpp>
using namespace deathsdoor::nodes;
int main(){
    LinkedList<int> list(LinkedListNode<int>(1));
    for (auto current = std::move(list.getHead()); current != nullptr; current = std::move(current->getNext())) {
        std::cout << current->getValue() << " ";
    }
    return 0;
}