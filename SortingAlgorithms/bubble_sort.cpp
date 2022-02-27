#include <iostream>
#include <vector>

#include "print_arr.hpp"

using namespace std;

void swap(vector<int> &arr, int index1, int index2) {
  int tmp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = tmp;
}

void bubble_sort(vector<int> &arr) {
  bool swap_in_iter = true;
  int sorted_index = arr.size() - 1;
  while (swap_in_iter) {
    swap_in_iter = false;
    for (int i = 0; i < sorted_index; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(arr, i, i + 1);
        swap_in_iter = true;
      }
    }
    sorted_index--;
  }
}

int main() {
  vector<int> arr{1, 5, 9, 0, -1, 3, -8, 50};
  // vector<int> arr{2, 3, 4, 1, 5};
  print_arr(arr);
  bubble_sort(arr);
  print_arr(arr);
}