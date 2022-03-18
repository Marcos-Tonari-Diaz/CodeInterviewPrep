#include <iostream>
#include <memory>
#include <unordered_set>

#include "../../DataStructures/LinkedList/singly_linked_list.hpp"

using namespace std;

int find_nth_to_last_element(SinglyLinkedList& list, int n) {
  int depth = 0;
  Node* current_node = list.getHeadNode();
  while (current_node != nullptr) {
    current_node = current_node->getNext().get();
    depth++;
  }
  int counter = depth - n;
  current_node = list.getHeadNode();
  while (counter > 0) {
    current_node = current_node->getNext().get();
    counter--;
  }
  return current_node->getData();
}

int main() {
  SinglyLinkedList list;
  list.appendToTail(1);
  list.appendToTail(2);
  list.appendToTail(3);
  list.appendToTail(3);
  list.appendToTail(5);
  list.appendToTail(6);
  list.appendToTail(7);
  list.printList();
  int n = 2;
  cout << n << " to last: " << find_nth_to_last_element(list, n) << endl;
  n = 4;
  cout << n << " to last: " << find_nth_to_last_element(list, n) << endl;
  n = 7;
  cout << n << " to last: " << find_nth_to_last_element(list, n) << endl;
  // list.printList();
  return 0;
}