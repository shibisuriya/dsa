#include <bits/stdc++.h>

using namespace std;

class Solution {
     private:
      unordered_map<int, vector<int>>* adjacency_list;
      vector<bool> visited;
      vector<bool> path_visited;

      bool has_cycle(int node) {
            if (!path_visited[node]) {
                  visited[node] = true;
                  path_visited[node] = true;
                  for (int& vertex : (*adjacency_list)[node]) {
                        if (has_cycle(vertex)) {
                              return true;
                        }
                  }
                  path_visited[node] = false;
                  return false;
            }

            return true; // has cycle...
      }

     public:
      bool detect_cycle(unordered_map<int, vector<int>>& adjacency_list) {
            this->adjacency_list = &adjacency_list;
            this->visited = vector<bool>(
                adjacency_list.size() + 1,
                false); // node numbering start with 1 not 0. So obiviosuly visited[0] and path_visited[0] will go to waste.
            this->path_visited = vector<bool>(adjacency_list.size() + 1, false);

            for (int i = 1; i < visited.size() + 1; i++) {
                  if (!visited[i] && has_cycle(i)) {
                        return true;
                  };
            }

            return false;
      }
};

unordered_map<int, vector<int>> deserialize() {
      unordered_map<int, vector<int>> adjacency_list;
      string line = "";
      while (getline(cin, line)) {
            istringstream iss(line);
            int node = 0, vertex = 0;
            iss >> node;
            vector<int> vertices;
            while (iss >> vertex) {
                  vertices.push_back(vertex);
            }
            adjacency_list[node] = vertices;
      }
      return adjacency_list;
}

int main() {
      Solution solution;
      unordered_map<int, vector<int>> adjacency_list = deserialize();
      bool has_cycle = solution.detect_cycle(adjacency_list);

      cout << "The undirected graph " << (has_cycle ? "has " : "doesn't have") << " cycle!";

      return 0;
}
