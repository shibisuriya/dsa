#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> deserialize() {
      string line = "";
      unordered_map<int, vector<int>> adjacency_list;
      while (getline(cin, line)) {
            istringstream iss(line);
            int vertex = 0, edge = 0;
            iss >> vertex;
            while (iss >> edge) {
                  adjacency_list[vertex].push_back(edge);
            }
      }
      return adjacency_list;
}

class Solution {
     public:
      bool is_cyclical(unordered_map<int, vector<int>> adjacency_list) {
            vector<int> visited(adjacency_list.size() + 1, false);
            queue<pair<int, int>> q;
            q.push(make_pair(1, -1));

            while (!q.empty()) {
                  pair<int, int> item = q.front();
                  int node = item.first;
                  int from = item.second;
                  q.pop();

                  if (!visited[node]) {
                        visited[node] = true;
                        for (int i = 0; i < adjacency_list[node].size(); i++) {
                              if (!visited[adjacency_list[node][i]]) {
                                    q.push(make_pair(adjacency_list[node][i], node));
                              }
                        }
                  } else if (from != node) {
                        return true;
                  }
            }

            return false;
      }
};

int main() {
      Solution solution;
      unordered_map<int, vector<int>> adjacency_list = deserialize();
      bool is_cyclical = solution.is_cyclical(adjacency_list);
      cout << "Is cyclical -> " << is_cyclical << endl;

      return 0;
}
