#include "binary_tree.hpp"

#include <deque>
#include <iostream>
#include <memory>
#include <stack>

using namespace std;

int main() {
  BinarySearchTree tree;
  tree.insert(5);
  tree.insert(8);
  tree.insert(2);
  tree.insert(1);
  tree.insert(9);
  tree.insert(3);
  tree.insert(7);
  //        5
  //      2    8
  //     1 3  7  9
  // tree.inOrderTraversal(tree.getRoot());
  // tree.preOrderTraversal(tree.getRoot());
  // tree.postOrderTraversal(tree.getRoot());
  // tree.breadthFirstSearch();
  tree.depthFirstSearch();
  return 0;
}
