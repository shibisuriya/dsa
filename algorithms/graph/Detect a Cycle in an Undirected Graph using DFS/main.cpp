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
     private:
      bool dfs(int node, int parent, vector<bool>& visited, unordered_map<int, vector<int>>& adjacency_matrix) {
            for (int& i : adjacency_matrix[node]) {
                  if (!visited[i]) {
                        visited[i] = true;
                        dfs(i, node, visited, adjacency_matrix);
                  } else {
                        if (i != parent) {
                              return true;
                        }
                  }
            }
            return false;
      }

     public:
      bool has_cycle(unordered_map<int, vector<int>> adjacency_matrix) {
            vector<bool> visited(adjacency_matrix.size() + 1, false); // visited[0] will go to waste, but it is okay!
            return dfs(1, -1, visited, adjacency_matrix);
      }
};

int main() {
      unordered_map<int, vector<int>> adjacency_list = deserialize();
      Solution solution;
      bool has_cycle = solution.has_cycle(adjacency_list);
      cout << "The graph " << (has_cycle ? "has" : "doesn't have") << " cycle!" << endl;
      return 0;
}
