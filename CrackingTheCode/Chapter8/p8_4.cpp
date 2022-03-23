#include <iostream>
#include <string>
#include <vector>

using namespace std;

void string_permutations(string str, string substr, int str_len) {
  string str_temp = str;
  string substr_temp = substr;
  if (substr.size() == str_len) {
    cout << substr << endl;
    return;
  }
  for (int i = 0; i < str.size(); i++) {
    substr_temp.push_back(str[i]);
    str_temp.erase(i, 1);
    string_permutations(str_temp, substr_temp, str_len);
    str_temp = str;
    substr_temp = substr;
  }
}

int main() {
  string test_string = "abcd";
  string_permutations(test_string, "", test_string.size());
  return 0;
}