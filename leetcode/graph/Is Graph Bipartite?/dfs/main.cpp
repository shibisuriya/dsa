// https://leetcode.com/problems/is-graph-bipartite/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
     private:
      vector<int> color;
      vector<vector<int>>* graph;

      bool dfs(int node, int parent_color) {
            if (color[node] == -1) {
                  color[node] = parent_color;
                  for (int& it : (*graph)[node]) {
                        if (!dfs(it, parent_color == 0 ? 1 : 0)) {
                              return false;
                        };
                  }
            } else if (color[node] != parent_color) {
                  return false;
            }

            return true;
      }

     public:
      bool isBipartite(vector<vector<int>>& graph) {
            this->graph = &graph;
            color = vector<int>(graph.size(), -1);

            for (int i = 0; i < graph.size(); i++) {
                  if (color[i] == -1) {
                        if (!dfs(i, 0)) {
                              return false;
                        }
                  }
            }

            return true;
      }
};

int main() {
      Solution solution;

      vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

      graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};

      solution.isBipartite(graph);

      return 0;
}
