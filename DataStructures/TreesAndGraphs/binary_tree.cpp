#include "binary_tree.hpp"

#include <deque>
#include <iostream>
#include <memory>
#include <stack>

using namespace std;

// smaller values on the left (node comparison operator is <)
void BinarySearchTree::insert(int data) {
  BinaryTreeNode* current_node = nullptr;
  if (root.get() == nullptr) {
    root = make_shared<BinaryTreeNode>(data);
    return;
  }
  current_node = root.get();
  while (true) {
    if (data <= current_node->getData()) {
      if (current_node->getLeft() != nullptr)
        current_node = current_node->getLeft().get();
      else {
        current_node->insertLeft(data);
        break;
      }
    } else {
      if (current_node->getRight() != nullptr)
        current_node = current_node->getRight().get();
      else {
        current_node->insertRight(data);
        break;
      }
    }
  }
}

void BinarySearchTree::inOrderTraversal(shared_ptr<BinaryTreeNode>& node) {
  if (node->getLeft() != nullptr) inOrderTraversal(node->getLeft());
  cout << node->getData() << endl;
  if (node->getRight() != nullptr) inOrderTraversal(node->getRight());
}

void BinarySearchTree::preOrderTraversal(shared_ptr<BinaryTreeNode>& node) {
  cout << node->getData() << endl;
  if (node->getLeft() != nullptr) inOrderTraversal(node->getLeft());
  if (node->getRight() != nullptr) inOrderTraversal(node->getRight());
}

void BinarySearchTree::postOrderTraversal(shared_ptr<BinaryTreeNode>& node) {
  if (node->getLeft() != nullptr) inOrderTraversal(node->getLeft());
  if (node->getRight() != nullptr) inOrderTraversal(node->getRight());
  cout << node->getData() << endl;
}

void BinarySearchTree::breadthFirstSearch() {
  deque<shared_ptr<BinaryTreeNode>> node_queue;
  node_queue.push_back(move(root));
  while (!node_queue.empty()) {
    shared_ptr<BinaryTreeNode>& popped_node = node_queue.front();
    if (popped_node->getLeft() != nullptr)
      node_queue.push_back(move(popped_node->getLeft()));
    if (popped_node->getRight() != nullptr)
      node_queue.push_back(move(popped_node->getRight()));
    cout << popped_node->getData() << endl;
    node_queue.pop_front();
  }
}

void BinarySearchTree::depthFirstSearch() {
  stack<shared_ptr<BinaryTreeNode>> node_stack;
  node_stack.push(move(root));
  while (!node_stack.empty()) {
    shared_ptr<BinaryTreeNode> popped_node(move(node_stack.top()));
    node_stack.pop();
    cout << popped_node->getData() << endl;
    if (popped_node->getRight() != nullptr)
      node_stack.push(move(popped_node->getRight()));
    if (popped_node->getLeft() != nullptr)
      node_stack.push(move(popped_node->getLeft()));
  }
}