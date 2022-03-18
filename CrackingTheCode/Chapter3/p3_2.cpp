#include <iostream>
#include <memory>
#include <vector>

#include "../../DataStructures/Stacks_and_Queues/stack_linked_list.hpp"

using namespace std;

class SetOfStacks {
  int stack_size;
  int current_stack = 0;
  int current_stack_size = 0;
  vector<unique_ptr<StackLinkedList>> stack_list;

 public:
  SetOfStacks(int stack_size) : stack_size{stack_size} {
    stack_list.push_back(make_unique<StackLinkedList>());
  };
  void push(int data) {
    cout << current_stack << endl;
    if (current_stack_size <= stack_size) {
      stack_list[current_stack]->push(data);
      current_stack_size++;
    } else {
      stack_list.push_back(make_unique<StackLinkedList>());
      stack_list[++current_stack]->push(data);
      current_stack_size = 1;
    }
  }
  Node* pop() {
    cout << current_stack << endl;
    if (current_stack_size > 0) {
      current_stack_size--;
      return stack_list[current_stack]->pop();
    } else {
      if (stack_list.size() > 1) {
        current_stack_size = stack_size - 1;
        return stack_list[--current_stack]->pop();
      } else
        return nullptr;
    }
  }
};

// queue using two stacks:

int main() {
  SetOfStacks stack(1);
  stack.push(5);
  stack.push(6);
  stack.push(7);
  cout << stack.pop()->getData() << endl;
  cout << stack.pop()->getData() << endl;
  cout << stack.pop()->getData() << endl;
  return 0;
}