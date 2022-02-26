#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, int> hash_table{{"Dijkstra", 1972}, {"Scott", 1976}};

  hash_table["Ritchie"] = 1983;
  for (auto p : hash_table) cout << '{' << p.first << ',' << p.second << '}';
  hash_table.erase("Scott");
  cout << endl;
  for (auto p : hash_table) cout << '{' << p.first << ',' << p.second << '}';
  hash_table.clear();
  cout << endl;
  cout << "    hash_table.size(): " << hash_table.size() << endl;
  cout << hash_table["inexistant_key"] << endl;
  cout << hash_table.at("inexistant_key_2") << endl;

  return 0;
}