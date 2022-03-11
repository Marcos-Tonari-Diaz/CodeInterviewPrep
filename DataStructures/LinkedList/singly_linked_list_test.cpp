#include "singly_linked_list.hpp"

int main() {
  SinglyLinkedList list;
  list.appendToTail(1);
  list.appendToTail(2);
  list.appendToTail(3);
  list.appendToTail(4);
  list.appendToTail(5);
  list.printList();
  list.deleteNode(3);
  list.printList();
  list.deleteNode(5);
  list.printList();
  list.deleteNode(1);
  list.printList();
  return 0;
}