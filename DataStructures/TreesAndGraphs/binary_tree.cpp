#include <deque>
#include <iostream>
#include <memory>
#include <stack>

using namespace std;

// class BinaryTree {
//   unique_ptr<BinaryTreeNode> root;
//  public:
//     // insert into the first position from left to right available on a
//     certain depth
// //    void breadthFirstInsert(int data){

// //    }
// };

class BinaryTreeNode {
  int data;
  unique_ptr<BinaryTreeNode> left;
  unique_ptr<BinaryTreeNode> right;

 public:
  BinaryTreeNode() : data{0} {};
  BinaryTreeNode(int data) : data{data} {};
  unique_ptr<BinaryTreeNode>& getLeft() { return left; };
  unique_ptr<BinaryTreeNode>& getRight() { return right; };
  void insertLeft(int data) { left = make_unique<BinaryTreeNode>(data); };
  void insertRight(int data) { right = make_unique<BinaryTreeNode>(data); };
  int getData() { return data; }
};

class BinarySearchTree {
  unique_ptr<BinaryTreeNode> root;

 public:
  unique_ptr<BinaryTreeNode>& getRoot() { return root; };

  // smaller values on the left (node comparison operator is <)
  void insert(int data) {
    BinaryTreeNode* current_node = nullptr;
    if (root.get() == nullptr) {
      root = make_unique<BinaryTreeNode>(data);
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

  void inOrderTraversal(unique_ptr<BinaryTreeNode>& node) {
    if (node->getLeft() != nullptr) inOrderTraversal(node->getLeft());
    cout << node->getData() << endl;
    if (node->getRight() != nullptr) inOrderTraversal(node->getRight());
  }

  void preOrderTraversal(unique_ptr<BinaryTreeNode>& node) {
    cout << node->getData() << endl;
    if (node->getLeft() != nullptr) inOrderTraversal(node->getLeft());
    if (node->getRight() != nullptr) inOrderTraversal(node->getRight());
  }

  void postOrderTraversal(unique_ptr<BinaryTreeNode>& node) {
    if (node->getLeft() != nullptr) inOrderTraversal(node->getLeft());
    if (node->getRight() != nullptr) inOrderTraversal(node->getRight());
    cout << node->getData() << endl;
  }

  void breadthFirstSearch(unique_ptr<BinaryTreeNode>& root) {
    deque<unique_ptr<BinaryTreeNode>> node_queue;
    node_queue.push_back(move(root));
    while (!node_queue.empty()) {
      unique_ptr<BinaryTreeNode>& popped_node = node_queue.front();
      if (popped_node->getLeft() != nullptr)
        node_queue.push_back(move(popped_node->getLeft()));
      if (popped_node->getRight() != nullptr)
        node_queue.push_back(move(popped_node->getRight()));
      cout << popped_node->getData() << endl;
      node_queue.pop_front();
    }
  }

  void depthFirstSearch(unique_ptr<BinaryTreeNode>& root) {
    stack<unique_ptr<BinaryTreeNode>> node_stack;
    node_stack.push(move(root));
    while (!node_stack.empty()) {
      unique_ptr<BinaryTreeNode> popped_node(move(node_stack.top()));
      node_stack.pop();
      cout << popped_node->getData() << endl;
      if (popped_node->getRight() != nullptr)
        node_stack.push(move(popped_node->getRight()));
      if (popped_node->getLeft() != nullptr)
        node_stack.push(move(popped_node->getLeft()));
    }
  }
};

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
  // tree.breadthFirstSearch(tree.getRoot());
  tree.depthFirstSearch(tree.getRoot());
  return 0;
}
