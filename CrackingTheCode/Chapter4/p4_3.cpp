#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "../../DataStructures/TreesAndGraphs/binary_tree.hpp"

using namespace std;

// create_minimum_height_tree(0, 8)
// create_minimum_height_tree(0, 3) left
// create_minimum_height_tree(5, 8) right
// create_minimum_height_tree(0, 0) left left
// create_minimum_height_tree(2, 3) left right
// base cases: 1 element - add to the tree

void create_minimum_height_tree(int sorted_arr[], int left_ix, int right_ix,
                                shared_ptr<BinaryTreeNode>& subtree_root) {
  if (left_ix == right_ix) {
    subtree_root = make_shared<BinaryTreeNode>(sorted_arr[left_ix]);
    return;
  }
  int middle_ix = (left_ix + right_ix) / 2;
  cout << middle_ix << endl;
  subtree_root = make_shared<BinaryTreeNode>(sorted_arr[middle_ix]);
  create_minimum_height_tree(sorted_arr, left_ix, middle_ix - 1,
                             subtree_root->getLeft());
  create_minimum_height_tree(sorted_arr, middle_ix + 1, right_ix,
                             subtree_root->getRight());
}

void inOrderTraversal(shared_ptr<BinaryTreeNode>& node) {
  if (node->getLeft() != nullptr) inOrderTraversal(node->getLeft());
  cout << node->getData() << endl;
  if (node->getRight() != nullptr) inOrderTraversal(node->getRight());
}

int main() {
  int sorted_arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  shared_ptr<BinaryTreeNode> root;
  create_minimum_height_tree(sorted_arr, 0, 8, root);
  // inOrderTraversal(root);
  return 0;
}