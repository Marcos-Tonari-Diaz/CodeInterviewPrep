#include <iostream>
#include <vector>

using namespace std;

// find when the rotated arr changes ordering
int find_min_rot_ord_arr(vector<int> arr) {
  int left_ix = 0;
  int right_ix = arr.size() - 1;
  int middle_ix = (left_ix + right_ix) / 2;
  while (left_ix <= right_ix) {
    if (arr[middle_ix + 1] < arr[middle_ix])
      return arr[middle_ix + 1];
    else if (arr[middle_ix] < arr[middle_ix - 1])
      return arr[middle_ix];
    if (arr[left_ix] > arr[middle_ix])
      right_ix = middle_ix;
    else if (arr[right_ix] < arr[middle_ix])
      left_ix = middle_ix;
    middle_ix = (left_ix + right_ix) / 2;
  }
}

int main() {
  vector<int> rotated_ord_arr{4, 5, 6, 7, 1, 2, 3};
  vector<int> rotated_ord_arr2{8, 9, 1, 2, 3, 4, 5, 6, 7};
  vector<int> rotated_ord_arr3{9, 1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> rotated_ord_arr4{2, 3, 4, 5, 6, 7, 1};
  cout << find_min_rot_ord_arr(rotated_ord_arr) << endl;
  cout << find_min_rot_ord_arr(rotated_ord_arr2) << endl;
  cout << find_min_rot_ord_arr(rotated_ord_arr3) << endl;
  cout << find_min_rot_ord_arr(rotated_ord_arr4) << endl;
  return 0;
}