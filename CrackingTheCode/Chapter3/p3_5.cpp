#include <iostream>
#include <memory>
#include <vector>

#include "../../DataStructures/Stacks_and_Queues/stack_linked_list.hpp"

using namespace std;

class QueueTwoStacks {
  StackLinkedList push_stack;
  StackLinkedList pop_stack;

 public:
  void push(int data) { push_stack.push(data); }
  shared_ptr<Node> pop() {
    while (push_stack.peek() != nullptr) {
      pop_stack.push(push_stack.pop()->getData());
    }
    return pop_stack.pop();
  }
};

int main() {
  QueueTwoStacks queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  cout << queue.pop()->getData() << endl;
  cout << queue.pop()->getData() << endl;
  cout << queue.pop()->getData() << endl;
  return 0;
}