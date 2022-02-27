#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  unordered_multiset<string> multiset;
  multiset.insert("Arnold");
  multiset.insert("Arnold");
  cout << multiset.count("Arnold") << endl;
  multiset.erase(multiset.find("Arnold"));
  cout << multiset.count("Arnold") << endl;
  return 0;
}