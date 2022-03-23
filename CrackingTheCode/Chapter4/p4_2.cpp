#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool pathStartingFrom(vector<vector<int>>& graph, int start_node, int end_node,
                      vector<int>& visited) {
  for (int node : graph[start_node]) {
    if (find(visited.begin(), visited.end(), node) != visited.end()) continue;
    if (node == end_node) {
      return true;
    } else {
      visited.push_back(node);
      if (pathStartingFrom(graph, node, end_node, visited)) return true;
    }
  }
  return false;
}

bool pathExists(vector<vector<int>>& graph, int node1, int node2) {
  vector<int> visited1;
  vector<int> visited2;
  return pathStartingFrom(graph, node1, node2, visited1) or
         pathStartingFrom(graph, node2, node1, visited2);
}

int main() {
  vector<vector<int>> directed_graph{{1, 2, 3, 4}, {5}, {5}, {5, 7}, {},
                                     {6},          {},  {8}, {4}};
  // path exists
  cout << pathExists(directed_graph, 0, 8) << endl;
  // path exists
  cout << pathExists(directed_graph, 8, 4) << endl;
  // path does not exist
  cout << pathExists(directed_graph, 7, 6) << endl;
  // path does not exist
  cout << pathExists(directed_graph, 4, 2) << endl;
  return 0;
}