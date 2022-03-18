#include <memory>

#include "../node.hpp"
#include "stack_linked_list.hpp"

using namespace std;

int main() {
  StackLinkedList stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  cout << "peek " << stack.peek()->getData() << endl;
  stack.printList();
  cout << "pop " << stack.pop()->getData() << endl;
  cout << "pop " << stack.pop()->getData() << endl;
  stack.printList();
  cout << "pop " << stack.pop()->getData() << endl;
  stack.printList();
  stack.printList();
  return 0;
}