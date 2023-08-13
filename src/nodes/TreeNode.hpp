#pragma once
#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <iostream>
#include <memory>
#include <iomanip>
#include <functional>

/*
To Create .O file run this command :
    cd "C:\MinGW\bin"
    g++ -c "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\TreeNode.cpp" -o "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\TreeNode.o"

To Link with main.cpp file :
    g++ "main.cpp directory" "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\TreeNode.o" -o .exe file name

To Link with its test file :
    g++ "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\mains\TreeNodeMain.cpp" "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\TreeNode.o" -o treenodemain
*/


namespace deathsdoor::nodes {
    //TODO add funtion called new node
    //TODO remove static functions as they are useless
    //TODO add breadthFirstTraversal
    template<typename T>
    class TreeNode {
        public:
            using pointer = std::shared_ptr<TreeNode<T>>;
            using weakPointer = std::weak_ptr<TreeNode<T>>;
        private:
            T _value;
            pointer _left = nullptr;
            pointer _right = nullptr;
            weakPointer _parent;
            //Unnützlich
            virtual void unnuetzlich() const noexcept{}

            static void _printTree(const TreeNode<T>& root, int indent) noexcept{
                int width = 5;
                if(root.isRightNotNull()) _printTree(*root.getRight(), indent + width);
                std::cout << std::setw(indent) << "";
                std::cout << "-- " << root.getValue() << std::endl;
                if (root.isLeftNotNull()) _printTree(*root.getLeft(), indent + width);
            }
        public:
            TreeNode(const T value) noexcept: _value(value),_parent() {}
            TreeNode(const T value,const pointer left,const pointer right) noexcept: _value(value), _left(std::move(left)), _right(std::move(right)),_parent() {}

            T getValue() const noexcept{
                return _value;
            }
            void setValue(const T& value) noexcept{
                _value = value;
            }

            void setLeft(pointer left) noexcept{
                _left = std::move(left);
            }
            void setRight(pointer right) noexcept{
                _right = std::move(right);
            }

            void setParent(pointer parent) noexcept{
                this->_parent = std::move(parent);
            }

            pointer getParent() const noexcept{
                return this->_parent.lock();
            }

            bool hasParent() const noexcept{
                return this->_parent.lock() != nullptr;
            }

            const pointer& getLeft() const noexcept{
                return _left;
            }
            const pointer& getRight() const noexcept{
                return _right;
            }

            bool isLeftNull() const noexcept{
                return _left == nullptr;
            }
            bool isRightNull() const noexcept{
                return _right == nullptr;
            }

            bool isLeftNotNull() const noexcept{
                return _left != nullptr;
            }
            bool isRightNotNull() const noexcept{
                return _right != nullptr;
            }

            bool isBalanced() const noexcept{
                return std::abs((this->isLeftNotNull() ? this->_left->baumhoch() : -1) - (this->isRightNotNull() ? this->_right->baumhoch() : -1)) <= 1;
            }

            void printTree() const noexcept{
                _printTree(*this, 0);
            }

            int baumhoch() const noexcept{
                return 1 + std::max(this->isLeftNotNull() ? this->_left->baumhoch() : -1,this->isRightNotNull() ? this->_right->baumhoch() : -1);
            }

            void postOrderTraversal(std::function<void(const TreeNode<T>&)> operation) const noexcept{
                std::function<void(const TreeNode<T>& node)> postOrderLambda = [&](TreeNode<T>& node) -> void {
                    if(node.isLeftNotNull()) postOrderTraversal(operation, *node.getLeft());
                    if(node.isRightNotNull()) postOrderTraversal(operation, *node.getRight());
                    operation(node);
                };
                postOrderLambda(*this);
            }
            void postOrderTraversal(std::function<void(TreeNode<T>&)> operation) noexcept{
                std::function<void(TreeNode<T>& node)> postOrderLambda = [&](TreeNode<T>& node) -> void {
                    if(node.isLeftNotNull()) postOrderLambda(operation, *node.getLeft());
                    operation(node);
                    if(node.isRightNotNull()) postOrderLambda(operation, *node.getRight());
                };
                postOrderLambda(*this);
            }

            void inOrderTraversal(std::function<void(const TreeNode<T>&)> operation) const noexcept{
                std::function<void(const TreeNode<T>& node)> inOrderLambda = [&](TreeNode<T>& node) -> void {
                    if(node.isLeftNotNull()) inOrderTraversal(operation, *node.getLeft());
                    operation(node);
                    if(node.isRightNotNull()) inOrderTraversal(operation, *node.getRight());
                };
                inOrderLambda(*this);
            }
            void inOrderTraversal(std::function<void(TreeNode<T>&)> operation) noexcept{
                std::function<void(TreeNode<T>& node)> inOrderLambda = [&](TreeNode<T>& node) -> void {
                    if(node.isLeftNotNull()) inOrderLambda(operation, *node.getLeft());
                    operation(node);
                    if(node.isRightNotNull()) inOrderLambda(operation, *node.getRight());
                };
                inOrderLambda(*this);
            }

            void preOrderTraversal(std::function<void(const TreeNode<T>&)> operation) const noexcept{
                std::function<void(const TreeNode<T>& node)> preOrderLambda = [&](TreeNode<T>& node) -> void {
                    operation(node);
                    if (node.isLeftNotNull()) preOrderLambda(*node.getLeft());
                    if (node.isRightNotNull()) preOrderLambda(*node.getRight());
                };
                preOrderLambda(*this);
            }
            void preOrderTraversal(std::function<void(TreeNode<T>&)> operation) noexcept {
                std::function<void(TreeNode<T>& node)> preOrderLambda = [&](TreeNode<T>& node) -> void {
                    operation(node);
                    if (node.isLeftNotNull()) preOrderLambda(*node.getLeft());
                    if (node.isRightNotNull()) preOrderLambda(*node.getRight());
                };
                preOrderLambda(*this);
            }

            template<typename X>
            bool isNodeOfType () const noexcept{
                return dynamic_cast<const X*>(this) != nullptr;
            }

            template<typename X>
            X* getNodeAs(){
                if(this->isNodeOfType<X>()) return dynamic_cast<X*>(this);
                throw std::invalid_argument(std::string("Can't convert from type ") + typeid(T).name() + " to type " + typeid(X).name());
            }
    };
}
#endif //TREENODE_HPP
