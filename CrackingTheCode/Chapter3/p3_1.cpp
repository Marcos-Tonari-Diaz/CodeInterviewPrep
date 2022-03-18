#include <iostream>
#include <vector>

using namespace std;

// divide the array by 3
class ThreeStacksSingleArray {
  int array_size;
  int* array;
  int stack_tops[3];

 public:
  ThreeStacksSingleArray(int array_size) : array_size{array_size} {
    array = new int[array_size];
    stack_tops[0] = 0;
    stack_tops[1] = array_size / 3;
    stack_tops[2] = 2 * array_size / 3;
  }
  ~ThreeStacksSingleArray() { delete array; }
  void push(int stack_num, int data) {
    if (stack_tops[stack_num] < (stack_num + 1) * array_size / 3)
      array[stack_tops[stack_num]++] = data;
    else
      cout << "out of bounds" << endl;
  }
  int pop(int stack_num) {
    if (stack_tops[stack_num] >= stack_num * array_size / 3)
      return array[--stack_tops[stack_num]];
    else
      cout << "out of bounds" << endl;
  }
};

int main() {
  ThreeStacksSingleArray stack(30);
  stack.push(0, 4);
  stack.push(1, 40);
  stack.push(2, 8);
  cout << stack.pop(0) << endl;
  cout << stack.pop(1) << endl;
  cout << stack.pop(2) << endl;
  for (int i = 0; i < 11; i++) stack.push(0, 4);
  stack.pop(2);
  stack.pop(2);
  return 0;
}