#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// O(n)
bool all_unique_characters_hash_table(string str) {
  unordered_map<char, bool> char_store;
  for (char c : str) {
    try {
      char_store.at(c);
    } catch (std::out_of_range no_key) {
      char_store[c] = true;
      continue;
    }
    return false;
  }
  return true;
}

// O(n)
bool all_unique_characters_hash_set(string str) {
  unordered_set<char> char_store;
  for (char c : str) {
    if (!char_store.insert(c).second) return false;
  }
  return true;
}

// sum of arithmetic progression 1+2+3+...+n-1
// O((1+n-1)*n/2) = O(n^2/2) = O(n^2)
bool all_unique_characters_naive(string str) {
  for (int i = 0; i < str.size(); i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (str[i] == str[j]) return false;
    }
  }
  return true;
}

bool all_unique_characters_ascii_table(string str) {
  bool ascii_store[256] = {false};
  for (int i = 0; i < str.size(); i++) {
    if (ascii_store[str[i]]) return false;
    ascii_store[str[i]] = true;
  }
  return true;
}

int main() {
  string unique{"abcdef"};
  string not_unique{"abcdefabcdfe"};
  cout << all_unique_characters_hash_table(unique) << endl;
  cout << all_unique_characters_hash_table(not_unique) << endl;
  cout << all_unique_characters_hash_set(unique) << endl;
  cout << all_unique_characters_hash_set(not_unique) << endl;
  cout << all_unique_characters_naive(unique) << endl;
  cout << all_unique_characters_naive(not_unique) << endl;
  cout << all_unique_characters_ascii_table(unique) << endl;
  cout << all_unique_characters_ascii_table(not_unique) << endl;
  return 0;
}