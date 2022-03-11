#include "singly_linked_list.hpp"

#include <iostream>
#include <memory>

#include "../node.hpp"

using namespace std;

void SinglyLinkedList::appendToTail(int data) {
  unique_ptr<Node> new_node = make_unique<Node>(data);
  Node* current_node = nullptr;
  if (head.get() == nullptr) {
    head = move(new_node);
    return;
  }
  current_node = head.get();
  while (current_node->getNext() != nullptr)
    current_node = current_node->getNext().get();
  current_node->setNext(new_node);
}

void SinglyLinkedList::printList() {
  cout << "list:" << endl;
  Node* current_node = head.get();
  while (current_node != nullptr) {
    cout << current_node->getData() << endl;
    current_node = current_node->getNext().get();
  }
}

void SinglyLinkedList::deleteNode(int data) {
  if (head.get() == nullptr) return;
  Node* current_node = head.get();
  if (head.get()->getData() == data) {
    head = move(head->getNext());
    return;
  }
  while (current_node != nullptr) {
    if (current_node->getNext()->getData() == data) {
      current_node->setNext(current_node->getNext()->getNext());
      return;
    }
    current_node = current_node->getNext().get();
  }
}