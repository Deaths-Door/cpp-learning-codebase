#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\TreeNode.hpp>
using namespace deathsdoor::nodes;

int main(){
    TreeNode<double> root = TreeNode<double>(1);
    root.setLeft(std::make_unique<TreeNode<double>>(2));
    root.getLeft()->setLeft(std::make_unique<TreeNode<double>>(4));
    root.getLeft()->getLeft()->setLeft(std::make_unique<TreeNode<double>>(4));
    root.setRight(std::make_unique<TreeNode<double>>(3));
    std::cout << "root.baumhoch() = "<< root.baumhoch() << std::endl;
    std::cout << "root.isBalanced() = " << std::boolalpha << root.isBalanced() << std::endl;
    root.printTree();
    return 0;
}
