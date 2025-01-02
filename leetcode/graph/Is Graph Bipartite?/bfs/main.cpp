// https://leetcode.com/problems/is-graph-bipartite/description/

#include <bits/stdc++.h>

using namespace std;

// What are bipartite graph?
// If you can color the graph with 2 colors such that no
// adjacent nodes have the same color...
//
// Liner graphs (graphs that don't have a cycle) are always biparite.
//
// Any graph with even cycle length is biparite.
//
// Any graph with odd cycle length will not be biparite.

class Solution {
     public:
      bool isBipartite(vector<vector<int>>& graph) {
            vector<int> color(graph.size(), -1);

            for (int i = 0; i < color.size(); i++) {
                  if (color[i] == -1) {
                        queue<int> q;
                        q.push(i);
                        color[i] = 0;
                        while (!q.empty()) {
                              int node = q.front();
                              q.pop();
                              for (int& it : graph[node]) {
                                    if (color[it] == -1) {
                                          q.push(it);
                                          color[it] = color[node] == 0 ? 1 : 0;
                                    } else if (color[it] == color[node]) {
                                          return false;
                                    }
                              }
                        }
                  }
            }
            return true;
      }
};

int main() {
      Solution solution;
      vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

      solution.isBipartite(graph);

      return 0;
}
