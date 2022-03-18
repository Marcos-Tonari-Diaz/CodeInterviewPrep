#include <iostream>
#include <vector>

using namespace std;

// top-down
int fibonnaci_recursive_topdown(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fibonnaci_recursive_topdown(n - 2) +
         fibonnaci_recursive_topdown(n - 1);
}

// bottom-up
int fibonnaci_recursive_bottomup(int n) {
  vector<int> fibonnaci_store;
  fibonnaci_store.resize(n + 1, 0);
  fibonnaci_store[0] = 0;
  fibonnaci_store[1] = 1;
  int i = 0;
  for (i = 2; i <= n; i++)
    fibonnaci_store[i] = fibonnaci_store[i - 2] + fibonnaci_store[i - 1];
  return fibonnaci_store[fibonnaci_store.size() - 1];
}

int main() {
  // 34
  cout << fibonnaci_recursive_topdown(9) << endl;
  cout << fibonnaci_recursive_bottomup(9) << endl;
  return 0;
}