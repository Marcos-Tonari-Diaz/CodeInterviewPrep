#include <iostream>
#include <memory>
#include <unordered_set>

#include "../../DataStructures/LinkedList/singly_linked_list.hpp"

using namespace std;

// find the node's parent, then delete it
void delete_given_node(SinglyLinkedList& list, Node* node) {
  if (node == nullptr) return;
  if (list.getHeadNode() == node) {
    list.setHeadNode(node->getNext());
    return;
  }
  Node* parent = list.getHeadNode();
  while (parent->getNext() != nullptr) {
    if (parent->getNext().get() == node) break;
    parent = parent->getNext().get();
  }
  parent->setNext(parent->getNext()->getNext());
}

int main() {
  SinglyLinkedList list;
  list.appendToTail(1);
  list.appendToTail(2);
  list.appendToTail(3);
  list.appendToTail(4);
  list.appendToTail(5);
  list.appendToTail(6);
  list.appendToTail(7);
  list.printList();
  int depth = 1;
  Node* todelete = list.getHeadNode();
  depth--;
  for (depth; depth > 0; depth--) {
    todelete = todelete->getNext().get();
  }
  cout << "delete node " << todelete->getData() << endl;
  delete_given_node(list, todelete);
  list.printList();
  return 0;
}