#include <iostream>
#include <memory>
#include <unordered_set>

#include "../../DataStructures/LinkedList/singly_linked_list.hpp"

using namespace std;

// considering the lists have the same size
SinglyLinkedList& sum_list_numbers(SinglyLinkedList& list_a,
                                   SinglyLinkedList& list_b) {
  SinglyLinkedList* sum_list = new SinglyLinkedList();
  Node* num_list_a = list_a.getHeadNode();
  Node* num_list_b = list_b.getHeadNode();
  bool carry = false;
  while (num_list_a != nullptr or num_list_b != nullptr) {
    sum_list->appendToTail(
        ((num_list_a->getData() + num_list_b->getData()) % 10) +
        (carry ? 1 : 0));
    carry =
        (num_list_a->getData() + num_list_b->getData() + (carry ? 1 : 0)) >= 10
            ? true
            : false;
    num_list_a = num_list_a->getNext().get();
    num_list_b = num_list_b->getNext().get();
  }
  return *sum_list;
}

int main() {
  SinglyLinkedList list_a;
  list_a.appendToTail(3);
  list_a.appendToTail(1);
  list_a.appendToTail(5);
  SinglyLinkedList list_b;
  list_b.appendToTail(5);
  list_b.appendToTail(9);
  list_b.appendToTail(2);
  sum_list_numbers(list_a, list_b).printList();
  return 0;
}