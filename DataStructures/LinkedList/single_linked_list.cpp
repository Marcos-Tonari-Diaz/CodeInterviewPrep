#include <iostream>
#include <memory>

#include "../node.hpp"

using namespace std;

class LinkedList {
  unique_ptr<Node> head;

 public:
  LinkedList() : head{nullptr} {};

  void appendToTail(int data) {
    unique_ptr<Node> new_node = make_unique<Node>(data);
    Node* current_node = nullptr;
    if (head.get() == nullptr) {
      head = move(new_node);
      return;
    } else {
      current_node = head.get();
      while (current_node->getNext() != nullptr)
        current_node = current_node->getNext().get();
      current_node->setNext(new_node);
    }
  }

  void printList() {
    cout << "list:" << endl;
    Node* current_node = head.get();
    while (current_node != nullptr) {
      cout << current_node->getData() << endl;
      current_node = current_node->getNext().get();
    }
  }

  void deleteNode(int data) {
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
};

int main() {
  LinkedList list;
  list.appendToTail(1);
  list.appendToTail(2);
  list.appendToTail(3);
  list.appendToTail(4);
  list.printList();
  list.deleteNode(3);
  list.printList();
  list.deleteNode(1);
  list.printList();
  return 0;
}