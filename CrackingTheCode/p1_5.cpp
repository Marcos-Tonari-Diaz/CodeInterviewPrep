#include <iostream>

using namespace std;

void replace_space_with_substring(string &input, string &output) {
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == ' ') {
      output.append("%");
      output.append("2");
      output.append("0");
    } else {
      output.append(string(1, input[i]));
    }
  }
}

void replace_space_with_substring_inplace(string &input) {
  unsigned num_spaces = 0;
  unsigned new_size = 0;
  unsigned original_size = input.size();
  for (char c : input)
    if (c == ' ') num_spaces++;
  new_size = input.size() + num_spaces * 2;
  input.resize(new_size);
  new_size--;
  for (int i = original_size - 1; i >= 0; i--) {
    if (input[i] == ' ') {
      input[new_size--] = '0';
      input[new_size--] = '2';
      input[new_size--] = '%';
    } else {
      input[new_size--] = input[i];
    }
  }
}

int main() {
  string input{"abc def ghi "};
  replace_space_with_substring_inplace(input);
  cout << input << endl;
  return 0;
}