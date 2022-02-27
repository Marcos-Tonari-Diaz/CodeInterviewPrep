#include <iostream>

using namespace std;

bool are_strs_palindromes(string str1, string str2) {
  if (str1.size() != str2.size()) return false;
  int forward_index = 0;
  int reverse_index = str2.size() - 1;
  while (forward_index < reverse_index) {
    if (str1[forward_index++] != str2[reverse_index--]) return false;
  }
  return true;
}

int main() {
  string str1{"abcd"};
  string str2{"dcba"};
  string str3{"abcd"};
  string str4{"dcab"};
  string str5{"abcd"};
  string str6{"dcab"};
  cout << are_strs_palindromes(str1, str2) << endl;
  cout << are_strs_palindromes(str3, str4) << endl;
  cout << are_strs_palindromes(str5, str6) << endl;
  return 0;
}