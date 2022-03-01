#include <vector>

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

// void query_sum(vector<unsigned int> &arr, int a, int b, int k){
//     for (int i=a; i<=b; i++)
//         arr[i]+=k;
// }

// long arrayManipulation(int n, vector<vector<int>> queries) {
//     vector<unsigned int> arr;
//     arr.resize(n, 0);
//     for (auto query: queries){
//         query_sum(arr, query[0], query[1], query[2]);
//     }
//     sort(arr.begin(), arr.end());
//     return arr[n-1];
// }

// long arrayManipulation(int n, vector<vector<int>> queries) {
//     int current_max_index = 0;
//     vector<unsigned> sum_arr;
//     sum_arr.resize(n, 0);
//     int a;
//     int b;
//     int k;
//     for (int i=0; i<n; i++){
//         for (auto query: queries){
//             a = query[0];
//             b = query[2];
//             k = query[2];
//             if (i>=a and i<=b) sum_arr[i]+=k;
//         }
//         if (sum_arr[i] > sum_arr[current_max_index]) current_max_index = i;
//     }
//     return sum_arr[current_max_index];
// }

long arrayManipulation(int n, vector<vector<int>> queries) {
  vector<long> sum_arr;
  int a;
  int b;
  int k;
  for (auto query : queries) {
    a = query[0];
    b = query[1];
    k = query[2];
  }
}