#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> deserialize() {
      unordered_map<int, vector<int>> adjacency_list;
      string line = "";
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
      vector<bool> visited; // Obiviously visited[0] will go to waste!
      unordered_map<int, vector<int>> adjacency_list;
      vector<int> dfs;

      void traverse(int node) {
            if (this->visited[node]) {
                  return;
            }

            this->visited[node] = true;
            this->dfs.push_back(node);

            for (int& vertex : adjacency_list[node]) {
                  traverse(vertex);
            }
      }

     public:
      vector<int> get_dfs(unordered_map<int, vector<int>> adjacency_list) {
            this->adjacency_list = adjacency_list;
            this->visited = vector<bool>(adjacency_list.size() + 1, false);
            traverse(1); // start the dfs from node 1.
            return this->dfs;
      }
};

int main() {
      unordered_map<int, vector<int>> adjacency_list = deserialize();
      Solution solution;
      vector<int> dfs = solution.get_dfs(adjacency_list);
      cout << "DFS -> ";
      for (int& vertex : dfs) {
            cout << vertex << " ";
      }
      cout << endl;
      return 0;
}
