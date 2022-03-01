#include <algorithm>
#include <iostream>
#include <vector>

#include "SortingAlgorithms/print_arr.hpp"

using namespace std;

// returns index of searched value, -1 if not found
int binary_search(vector<int> arr, int value) {
  unsigned left_index = 0;
  unsigned right_index = arr.size() - 1;
  unsigned middle_index = (left_index + right_index) / 2;
  while (left_index <= right_index) {
    if (arr[middle_index] == value)
      return middle_index;
    else if (arr[middle_index] < value)
      left_index = middle_index + 1;
    else
      right_index = middle_index - 1;
    middle_index = left_index + (right_index - left_index) / 2;
  }
  return -1;
}

int main() {
  // odd size (size=9)
  vector<int> odd_arr{1, 5, 3, 4, 0, -1, -3, 50, 90};
  sort(odd_arr.begin(), odd_arr.end());
  print_arr(odd_arr);
  cout << binary_search(odd_arr, 5) << endl;
  cout << binary_search(odd_arr, 50) << endl;
  cout << binary_search(odd_arr, 3) << endl;
  cout << binary_search(odd_arr, 1) << endl;
  cout << binary_search(odd_arr, 90) << endl;

  // even size (size=8)
  vector<int> even_arr{1, 5, 3, 4, -1, -3, 50, 90};
  sort(even_arr.begin(), even_arr.end());
  print_arr(even_arr);
  cout << binary_search(even_arr, 5) << endl;
  cout << binary_search(even_arr, 50) << endl;
  cout << binary_search(even_arr, 3) << endl;
  cout << binary_search(even_arr, 1) << endl;
  cout << binary_search(even_arr, 90) << endl;

  vector<int> one_arr{1};
  cout << binary_search(one_arr, 1) << endl;
  cout << binary_search(one_arr, 5) << endl;
  return 0;
}