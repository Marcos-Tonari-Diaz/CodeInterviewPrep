#ifndef STACK_LINKED_LIST
#define STACK_LINKED_LIST

#include <iostream>
#include <memory>

#include "../node.hpp"

using namespace std;

class StackLinkedList {
  unique_ptr<Node> head;

 public:
  StackLinkedList() : head{nullptr} {};
  void push(int data) {
    unique_ptr<Node> new_node = make_unique<Node>(data);
    new_node->setNext(head);
    head = move(new_node);
  }
  Node* pop() {
    if (head == nullptr) return nullptr;
    Node* popped_node = head->getNext().get();
    head = move(head->getNext());
    return popped_node;
  }
  void printList() {
    cout << "list:" << endl;
    Node* current_node = head.get();
    while (current_node != nullptr) {
      cout << current_node->getData() << endl;
      current_node = current_node->getNext().get();
    }
  }
};

#endif