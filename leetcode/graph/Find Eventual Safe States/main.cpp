// https://leetcode.com/problems/find-eventual-safe-states/

#include <bits/stdc++.h>

using namespace std;

class Solution {
     private:
      vector<int> path_visited, visited;
      vector<vector<int>>* graph;

      bool has_cycle(int node) {
            path_visited[node] = true;
            visited[node] = true;

            for (int& vertex : (*graph)[node]) {
                  if (!path_visited[vertex]) {
                        if (!visited[vertex] && has_cycle(vertex)) {
                              return true;
                        }
                  } else {
                        return true;
                  }
            }
            path_visited[node] = false;
            return false;
      }

     public:
      vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            this->graph = &graph;
            this->path_visited = vector<int>(graph.size(), false);
            this->visited = vector<int>(graph.size(), false);

            vector<int> safe_nodes;

            for (int i = 0; i < graph.size(); i++) {
                  if (!has_cycle(i)) {
                        safe_nodes.push_back(i);
                  }
            }

            return safe_nodes;
      }
};

int main() {
      Solution solution;
      vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
      solution.eventualSafeNodes(graph);
}
