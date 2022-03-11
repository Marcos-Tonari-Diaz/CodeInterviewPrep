#include <iostream>

using namespace std;

void remove_duplicate_chars_naive(string& str) {
  for (int i = 0; i < str.size(); i++) {
    for (int j = 0; j < str.size(); j++) {
      if (i != j && str[i] == str[j]) {
        str.erase(str.begin() + j);
      }
    }
  }
  cout << str << endl;
}

int main() {
  string str{"abcde"};
  string str2{"aabbbccccdea"};
  string null_str{};
  string str3{"aaaa"};
  string str4{"abcabcabc"};
  //   remove_duplicate_chars_naive(str);
  //   remove_duplicate_chars_naive(str2);
  remove_duplicate_chars_naive(str);
  remove_duplicate_chars_naive(str2);
  remove_duplicate_chars_naive(null_str);
  remove_duplicate_chars_naive(str3);
  remove_duplicate_chars_naive(str4);
  //   cout << str << endl;
  return 0;
}