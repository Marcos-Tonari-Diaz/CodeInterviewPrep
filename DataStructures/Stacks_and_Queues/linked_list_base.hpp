#ifndef LINKED_LIST_BASE
#define LINKED_LIST_BASE

#include <iostream>
#include <memory>

#include "../node.hpp"

using namespace std;

class LinkedListBase {
 protected:
  shared_ptr<Node> head;

 public:
  LinkedListBase() : head{nullptr} {};
  void printList() {
    cout << "list:" << endl;
    shared_ptr<Node> current_node = head;
    while (current_node != nullptr) {
      cout << current_node->getData() << endl;
      current_node = current_node->getNext();
    }
  }
};

#endif