#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\TreeNode.hpp>
using namespace deathsdoor::nodes;

template<typename T> void TreeNode<T>::_postOrderTraversalConst(std::function<void(const TreeNode<T>&)> operation, const TreeNode<T>& root) noexcept{
    if(root.isLeftNotNull()) postOrderTraversal(operation, *root.getLeft());
    if(root.isRightNotNull()) postOrderTraversal(operation, *root.getRight());
    operation(root);
}
template<typename T> void TreeNode<T>::_postOrderTraversal(std::function<void(TreeNode<T>&)> operation,TreeNode<T>& root) noexcept {
    if(root.isLeftNotNull()) postOrderTraversal(operation, *root.getLeft());
    if(root.isRightNotNull()) postOrderTraversal(operation, *root.getRight());
    operation(root);
}
template<typename T> void TreeNode<T>::postOrderTraversal(std::function<void(const TreeNode<T>&)> operation) const noexcept {
    _postOrderTraversalConst(operation, *this);
}
template<typename T> void TreeNode<T>::postOrderTraversal(std::function<void(TreeNode<T>&)> operation) noexcept {
    _postOrderTraversal(operation, *this);
}