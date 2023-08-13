#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\LinkedList.hpp>
using namespace deathsdoor::nodes;

//LinkedListNode CLASS
template<typename T> LinkedListNode<T>::LinkedListNode(const T value) noexcept : _value(value) {}

template<typename T> LinkedListNode<T>::LinkedListNode(const T value,const linkedlistNode node) noexcept : _value(value), _next(std::move(node)) {}

template<typename T> bool LinkedListNode<T>::isNextNull() const noexcept{
    return this->_next == nullptr;
}
template<typename T> bool LinkedListNode<T>::isNextNotNull() const noexcept{
    return this->_next != nullptr;
}

//LinkedList CLASS
template<typename T> LinkedList<T>::LinkedList(const LinkedListNode<T> node) noexcept: head(std::move(node)), tail(head.get()) {}

template<typename T> typename LinkedListNode<T>::linkedlistNode& LinkedList<T>::getHead() const noexcept{
    return this->head;
}
template<typename T> typename LinkedListNode<T>::linkedlistNode& LinkedList<T>::getTail() const noexcept{
    return this->tail;
}

template<typename T> int LinkedList<T>::getLength() const noexcept{
    return this->length;
}
template<typename T> bool LinkedList<T>::isEmpty() const noexcept{
    return this->length == 0;
}

template<typename T> void LinkedList<T>::insert(const T value) noexcept{
    this->insert(std::move(std::make_unique<LinkedListNode<T>>(value)));
}
template<typename T> void LinkedList<T>::insert(LinkedListNode<T> node) noexcept{
    this->tail->setNext(std::move(node));
    this->tail = this->tail->getNext();
    ++this->length;
}

template<typename T> void LinkedList<T>::insertAt(const T value,int index){
    this->insertAt(std::move(std::make_unique<LinkedListNode<T>>(value)),value);
}

template<typename T> void LinkedList<T>::insertAt(LinkedListNode<T> node,int index){
    if(index > length - 1) throw std::invalid_argument("Index " + std::to_string(index) + " out of Range if" + std::to_string(this->length));
    if(index == 0) this->insertAtHead(node);
    auto current = head.get();
    for(int i = 0; i < index - 1; ++i) current = current->getNext().get();
    node->setNext(std::move(current->getNext()));
    current->setNext(std::make_unique<LinkedListNode<T>>(node->getValue()));
    if(index == length - 1) this->tail = std::move(current->getNext());
    ++length;
}

template<typename T> void LinkedList<T>::insertAtHead(const T value) noexcept{
    this->insertAtHead(std::move(std::make_unique<LinkedListNode<T>>(value)));
}
template<typename T> void LinkedList<T>::insertAtHead(LinkedListNode<T> node) noexcept{
    node.setNext(std::move(head));
    head = std::make_unique<LinkedListNode<T>>(node.getValue());
    if (tail == nullptr) tail = std::move(head);
    ++length;
}

template<typename T> void LinkedList<T>::deleteNode(const T value) noexcept{
    if (length == 0) return;
    if (head->getValue() == value) {
        head = std::move(head->getNext());
        --length;
        return;
    }
    auto current = head.get();
    while (current->getNext() && current->getNext()->getValue() != value) {
        current = current->getNext().get();
    }
    if (current->getNext() == nullptr) return;
    current->setNext(std::move(current->getNext()->getNext()));
    --length;
}

template<typename T> void LinkedList<T>::deleteNodeAtPosition(const int position) noexcept{
    if (position >= length) return;
    if (position == 0) {
        head = std::move(head->getNext());
        --length;
        return;
    }
    auto current = head.get();
    for (int i = 0; i < position - 1; ++i) current = current->getNext().get();
    current->setNext(std::move(current->getNext()->getNext()));
    if (position == length - 1) tail = current;
    --length;
}

template<typename T> void LinkedList<T>::deleteAlle() noexcept{
    head = nullptr;
    tail = nullptr;
    length = 0;
}