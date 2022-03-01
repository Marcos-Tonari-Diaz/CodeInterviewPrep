#include <iostream>

using namespace std;

bool is_substring(string str, string substr) {
  return str.find(substr) != string::npos;
}

bool is_rotation(string original, string rotated) {
  if (original.size() != rotated.size()) return false;
  original.append(original);
  return is_substring(original, rotated);
}

int main() {
  // cout << is_substring("abcd", "dbc") << endl;
  cout << is_rotation("waterbottle", "erbottlewat") << endl;
  cout << is_rotation("waterbottle", "erbottlewae") << endl;
  return 0;
}