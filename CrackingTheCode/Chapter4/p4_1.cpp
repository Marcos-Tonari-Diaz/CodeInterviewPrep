#include <cmath>
#include <iostream>
#include <vector>

#include "../../DataStructures/TreesAndGraphs/binary_tree.hpp"

using namespace std;

int maxDepthSubtree(shared_ptr<BinaryTreeNode> node, int depth) {
  int left_subtree_depth = 0;
  int right_subtree_depth = 0;
  // leaf node
  if (node->getLeft() == nullptr and node->getRight() == nullptr) return depth;
  // non leaf node
  if (node->getLeft() != nullptr)
    left_subtree_depth = maxDepthSubtree(node->getLeft(), depth + 1);
  if (node->getRight() != nullptr)
    right_subtree_depth = maxDepthSubtree(node->getRight(), depth + 1);
  if (right_subtree_depth == 0 or left_subtree_depth == 0) return 0;
  if (abs(left_subtree_depth - right_subtree_depth) > 1)
    return 0;
  else {
    // root node
    if (depth == 0)
      return 1;
    else
      return max(left_subtree_depth, right_subtree_depth);
  }
}

bool isTreeBalanced(BinarySearchTree& tree) {
  return maxDepthSubtree(tree.getRoot(), 0) == 1 ? true : false;
}

int main() {
  BinarySearchTree balanced_tree;
  balanced_tree.insert(5);
  balanced_tree.insert(8);
  balanced_tree.insert(2);
  balanced_tree.insert(1);
  balanced_tree.insert(9);
  balanced_tree.insert(3);
  balanced_tree.insert(7);
  //        5
  //      2    8
  //     1 3  7  9
  cout << isTreeBalanced(balanced_tree) << endl;
  BinarySearchTree balanced_tree2;
  balanced_tree2.insert(5);
  balanced_tree2.insert(8);
  balanced_tree2.insert(2);
  balanced_tree2.insert(9);
  balanced_tree2.insert(7);
  //        5
  //      2    8
  //          7  9
  cout << isTreeBalanced(balanced_tree2) << endl;
  BinarySearchTree unbalanced_tree;
  unbalanced_tree.insert(5);
  unbalanced_tree.insert(8);
  unbalanced_tree.insert(9);
  unbalanced_tree.insert(7);
  //        5
  //           8
  //          7  9
  cout << isTreeBalanced(unbalanced_tree) << endl;
  return 0;
}