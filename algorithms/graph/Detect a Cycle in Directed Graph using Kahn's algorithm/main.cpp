
#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> deserialize() {
      string line = "";

      unordered_map<int, vector<int>> adjacency_list;

      while (getline(cin, line)) {
            istringstream iss(line);
            int node = 0, edge = 0;
            iss >> node;
            vector<int> edges;

            while (iss >> edge) {
                  edges.push_back(edge);
            }
            adjacency_list[node] = edges;
      }
      return adjacency_list;
}

class Solution {
     public:
      bool is_cycle_present(unordered_map<int, vector<int>> adjacency_list) {
            vector<int> topological_sort;
            vector<int> indegrees(adjacency_list.size());

            for (const pair<int, vector<int>>& item : adjacency_list) {
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

                  vector<int> edges = adjacency_list[node];

                  for (int& edge : edges) {
                        indegrees[edge]--;
                        if (indegrees[edge] == 0) {
                              q.push(edge);
                        }
                  }
            }

            return adjacency_list.size() == topological_sort.size();
      }
};

int main() {
      unordered_map<int, vector<int>> adjacency_list = deserialize();

      Solution solution;

      bool is_cycle_present = solution.is_cycle_present(adjacency_list);

      cout << "The supplied directed graph " << (is_cycle_present ? "has cycle(s)" : "doesn't have cycles") << "."
           << endl;

      return 0;
}
