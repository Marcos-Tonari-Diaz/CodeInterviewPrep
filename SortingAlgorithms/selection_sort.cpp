#include <iostream>
#include <vector>

#include "print_arr.hpp"

using namespace std;

void selection_sort(vector<int> &arr) {
  int temp;
  int minimum_index = 0;
  int num_swaps = 0;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[minimum_index]) minimum_index = j;
    }
    if (i != minimum_index) {
      temp = arr[i];
      arr[i] = arr[minimum_index];
      arr[minimum_index] = temp;
      print_arr(arr);
      num_swaps++;
    }
    minimum_index = i + 1;
  }
  cout << num_swaps << endl;
}

int main() {
  // vector<int> arr{1, 5, 9, 0, -1, 3, -8, 50};
  vector<int> arr{2, 3, 4, 1, 5};
  print_arr(arr);
  selection_sort(arr);
  return 0;
}