#include <iostream>
#include <stack>

using namespace std;

void reverse_string_stack(char* str, int size) {
  stack<char> char_stack;
  for (int i = 0; i < size - 1; i++) char_stack.push(str[i]);
  for (int i = 0; i < size - 1; i++) {
    str[i] = char_stack.top();
    char_stack.pop();
  }
  str[size - 1] = '\0';
}

void reverse_string(char* str) {
  char* reverse_ptr = str;
  char tmp;
  while (*reverse_ptr) {
    reverse_ptr++;
  }
  reverse_ptr--;
  while (str < reverse_ptr) {
    tmp = *str;
    *str = *reverse_ptr;
    *reverse_ptr = tmp;
    str++;
    reverse_ptr--;
  }
}

int main() {
  int size = 7;
  char str[] = "abcdef";
  reverse_string(str);
  //   reverse_string_stack(str, size);
  for (int i = 0; i < size; i++) cout << str[i];
  cout << endl;
  //   cout << (int)'\0' << endl;
  return 0;
}