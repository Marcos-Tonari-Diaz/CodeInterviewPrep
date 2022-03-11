#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

bool are_strs_anagrams(string str1, string str2) {
  if (str1.size() != str2.size()) return false;
  for (char c : str2) {
    size_t found_pos = str1.find(c);
    if (found_pos != string::npos) {
      str1.erase(found_pos, 1);
    }
  }
  if (str1.size() == 0)
    return true;
  else
    return false;
}

int main() {
  string str1{"abcd"};
  string str2{"abcd"};
  string str3{"abcd"};
  string str4{"badc"};
  string str5{"abcd"};
  string str6{"dcba"};
  string str7{"abce"};
  string str8{"dcba"};
  cout << are_strs_anagrams(str1, str2) << endl;
  cout << are_strs_anagrams(str3, str4) << endl;
  cout << are_strs_anagrams(str5, str6) << endl;
  cout << are_strs_anagrams(str7, str8) << endl;
  return 0;
}