#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <memory>

#include "../node.hpp"

using namespace std;

class SinglyLinkedList {
  unique_ptr<Node> head;

 public:
  SinglyLinkedList() : head{nullptr} {};
  Node* getHeadNode() { return head.get(); }
  void setHeadNode(unique_ptr<Node>& node) { head = move(node); }
  void appendToTail(int data);
  void printList();
  void deleteNode(int data);
};

#endif