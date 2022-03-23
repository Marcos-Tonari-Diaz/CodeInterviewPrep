#include <deque>
#include <iostream>
#include <memory>
#include <stack>

using namespace std;

class BinaryTreeNode {
  int data;
  shared_ptr<BinaryTreeNode> left;
  shared_ptr<BinaryTreeNode> right;

 public:
  BinaryTreeNode() : data{0} {};
  BinaryTreeNode(int data) : data{data} {};
  shared_ptr<BinaryTreeNode>& getLeft() { return left; };
  shared_ptr<BinaryTreeNode>& getRight() { return right; };
  void insertLeft(int data) { left = make_shared<BinaryTreeNode>(data); };
  void insertRight(int data) { right = make_shared<BinaryTreeNode>(data); };
  int getData() { return data; }
};

class BinarySearchTree {
  shared_ptr<BinaryTreeNode> root;

 public:
  shared_ptr<BinaryTreeNode>& getRoot() { return root; };
  void insert(int data);
  void inOrderTraversal(shared_ptr<BinaryTreeNode>& node);
  void preOrderTraversal(shared_ptr<BinaryTreeNode>& node);
  void postOrderTraversal(shared_ptr<BinaryTreeNode>& node);
  void breadthFirstSearch();
  void depthFirstSearch();
};