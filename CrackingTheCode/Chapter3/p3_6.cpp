#include <iostream>
#include <memory>
#include <vector>

#include "../../DataStructures/Stacks_and_Queues/stack_linked_list.hpp"

using namespace std;

void StackBubbleSort(StackLinkedList& stack) {
  StackLinkedList buffer_stack;
  bool swap_in_iter = true;
  shared_ptr<Node> popped_above = stack.pop();
  shared_ptr<Node> popped_under = stack.pop();
  cout << stack.peek() << endl;
  if (popped_above == nullptr) return;
  while (swap_in_iter) {
    swap_in_iter = false;
    while (popped_under != nullptr) {
      if (popped_above->getData() > popped_under->getData()) {
        stack.push(popped_above->getData());
        buffer_stack.push(popped_under->getData());
        swap_in_iter = true;
      } else {
        stack.push(popped_under->getData());
        buffer_stack.push(popped_above->getData());
      }
      popped_above = stack.pop();
      popped_under = stack.pop();
      // stack.printList();
    }
    stack.push(popped_above);
    // stack.printList();
    while (buffer_stack.peek() != nullptr) {
      stack.push(buffer_stack.pop());
    }
    // stack.printList();
  }
}

int main() {
  StackLinkedList stack;
  stack.push(1);
  stack.push(2);
  // stack.push(3);
  // stack.push(4);
  stack.printList();
  StackBubbleSort(stack);
  // stack.printList();
  return 0;
}