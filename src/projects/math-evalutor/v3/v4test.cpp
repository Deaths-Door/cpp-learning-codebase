#include <iostream>
#include "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\StandardForm.hpp"
#include "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\Operator.hpp"
using namespace deathsdoor::math;
using namespace deathsdoor::nodes;

int main(){
    auto root = Operator(Operator::Operation::ADD);
    root.setLeft(std::make_unique<StandardForm>(3.0));
    root.setRight(std::make_unique<StandardForm>(3.0));

    root.printTree();
    std::cout << "root.isNodeOfType<StandardForm>() = " << std::boolalpha << root.isNodeOfType<StandardForm>() << std::endl;
    std::cout << "root.isNodeOfType<Operator>() = " << std::boolalpha << root.isNodeOfType<Operator>() << std::endl;
    std::cout << "root.getLeft().isNodeOfType<StandardForm>() = " << std::boolalpha << root.getLeft()->isNodeOfType<StandardForm>() << std::endl;
    std::cout << "root.getLeft().isNodeOfType<Operator>()  = " << std::boolalpha << root.getLeft()->isNodeOfType<Operator>() << std::endl;

    StandardForm sf(1);
    root.preOrderTraversal([&sf](TreeNode<NodeType>& node){
        if(!node.isNodeOfType<Operator>()) return;
       // node = std::move(*node.getLeft()->getNodeAs<StandardForm>() + *node.getRight()->getNodeAs<StandardForm>());
       // if(!node.hasParent())
        sf = std::move(*node.getLeft()->getNodeAs<StandardForm>() + *node.getRight()->getNodeAs<StandardForm>());
        std::cout << "Answer = " << node.getValue() << std::endl;
        std::cout << "node.isNodeOfType<StandardForm>() = " << std::boolalpha << node.isNodeOfType<StandardForm>() << std::endl;
        std::cout << "node.isNodeOfType<Operator>() = " << std::boolalpha << node.isNodeOfType<Operator>() << std::endl;
        node.setLeft(nullptr);
        node.setRight(nullptr);
    });
    root.printTree();

//std::cout << "asnwer.isNodeOfType<StandardForm>() = " << std::boolalpha << root.isNodeOfType<StandardForm>() << std::endl;
  //  std::cout << "asnwer.isNodeOfType<Operator>()= " << std::boolalpha << root.isNodeOfType<Operator>() << std::endl;
 //   std::cout << "asnwer.realType = " << typeid(root).name() << std::endl;
    //std::cout << "Answer = " << root.getNodeAs<StandardForm>().toScientificNotation() << std::endl;
    std::cout << "Answer = " << sf << std::endl;
    return 0;
}
