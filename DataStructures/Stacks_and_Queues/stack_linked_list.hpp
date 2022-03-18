#ifndef STACK_LINKED_LIST
#define STACK_LINKED_LIST

#include <iostream>
#include <memory>

#include "../node.hpp"
#include "linked_list_base.hpp"

using namespace std;

class StackLinkedList : public LinkedListBase {
 public:
  StackLinkedList(){};
  void push(int data) {
    shared_ptr<Node> new_node = make_unique<Node>(data);
    new_node->setNext(head);
    head = move(new_node);
  }
  void push(shared_ptr<Node> node) {
    shared_ptr<Node> new_node(node);
    new_node->setNext(head);
    head = move(new_node);
  }
  shared_ptr<Node> pop() {
    if (head == nullptr) return nullptr;
    shared_ptr<Node> popped_node = head;
    head = move(head->getNext());
    return popped_node;
  }
  shared_ptr<Node> peek() {
    if (head != nullptr)
      return head;
    else
      return nullptr;
  }
};

#endif