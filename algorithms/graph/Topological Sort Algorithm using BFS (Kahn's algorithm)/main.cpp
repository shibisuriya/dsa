#include <bits/stdc++.h>

using namespace std;

// What is indegree of a node?
// The number of incoming edges to a node is called its n degree.

class Solution {
     public:
      vector<int> get_topological_sort(unordered_map<int, vector<int>> adjacency_list) {
            vector<int> indegrees(adjacency_list.size());
            vector<int> topological_sort;

            for (pair<int, vector<int>> item : adjacency_list) {
                  int node = item.first;
                  vector<int> edges = item.second;
                  for (int& edge : edges) {
                        indegrees[edge]++;
                  }
            }

            queue<int> q;

            for (int i = 0; i < indegrees.size(); i++) {
                  if (indegrees[i] == 0) {
                        q.push(i);
                  }
            }

            while (!q.empty()) {
                  int node = q.front();
                  q.pop();
                  topological_sort.push_back(node);
                  for (int& edge : adjacency_list[node]) {
                        indegrees[edge]--;
                        if (indegrees[edge] == 0) {
                              q.push(edge);
                        }
                  }
            }

            return topological_sort;
      }
};

unordered_map<int, vector<int>> deserialize() {
      string line = "";
      unordered_map<int, vector<int>> adjacency_list;

      while (getline(cin, line)) {
            istringstream iss(line);
            int node = 0, edge = 0;
            vector<int> edges;
            iss >> node;
            while (iss >> edge) {
                  edges.push_back(edge);
            }
            adjacency_list[node] = edges;
      }

      return adjacency_list;
}

int main() {
      unordered_map<int, vector<int>> adjacency_list = deserialize();
      Solution solution;
      vector<int> topological_sort = solution.get_topological_sort(adjacency_list);

      for (int& node : topological_sort) {
            cout << node << " ";
      }

      cout << endl;

      return 0;
}
