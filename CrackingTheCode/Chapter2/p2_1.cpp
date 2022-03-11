#include <iostream>
#include <memory>
#include <unordered_set>

#include "../../DataStructures/LinkedList/singly_linked_list.hpp"

using namespace std;

void remove_duplicates(SinglyLinkedList& list) {
  unordered_set<int> node_set;
  Node* current_node = list.getHeadNode();
  if (current_node != nullptr)
    node_set.insert(current_node->getData());
  else
    return;
  while (current_node->getNext() != nullptr) {
    if (node_set.count(current_node->getNext()->getData()) < 1)
      node_set.insert(current_node->getNext()->getData());
    else {
      node_set.erase(current_node->getNext()->getData());
      current_node->setNext(current_node->getNext()->getNext());
    }
    if (current_node->getNext() != nullptr) {
      current_node = current_node->getNext().get();
      node_set.insert(current_node->getData());
    } else
      break;
  }
}

int main() {
  SinglyLinkedList list;
  list.appendToTail(1);
  list.appendToTail(1);
  list.appendToTail(2);
  list.appendToTail(3);
  list.appendToTail(4);
  list.appendToTail(3);
  list.appendToTail(5);
  list.appendToTail(5);
  list.printList();
  remove_duplicates(list);
  list.printList();
  return 0;
}