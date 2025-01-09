// Topological sort
//
// Any linear ordering of vertices such that there is
// an edge between vertex u & vertex v, where u appears before v in that order.
//
// Topological sort only exists in DAG (Directed Acyclic grpah)!
// 1. If the graph is non directed, then an edge between A and B is an edge between B and A.
// 2. If the graph has cycles, and if nodes A and B belonged to the cyclic region of the graph, then
// A would lead to B and B would lead to A. Which means A can't come before B and B can't come before A.

#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> deserialize() {
      unordered_map<int, vector<int>> adjacency_list;
      string line = "";
      while (getline(cin, line)) {
            int vertex = 0, edge = 0;
            vector<int> edges;
            istringstream iss(line);
            iss >> vertex;

            while (iss >> edge) {
                  edges.push_back(edge);
            }

            adjacency_list[vertex] = edges;
      }

      return adjacency_list;
}

class Solution {
     private:
      unordered_set<int> visited;
      stack<int> s;
      unordered_map<int, vector<int>>* adjacency_list;

      void dfs(int node) {
            visited.insert(node);

            vector<int> edges = (*adjacency_list)[node];

            for (int& edge : edges) {
                  if (visited.find(edge) == visited.end()) {
                        dfs(edge);
                  }
            }

            s.push(node);
      }

     public:
      vector<int> find_topological_sort(unordered_map<int, vector<int>> adjacency_list) {
            this->adjacency_list = &adjacency_list;

            for (pair<const int, vector<int>>& item : adjacency_list) {
                  int key = item.first;
                  if (visited.find(key) == visited.end()) {
                        dfs(key);
                  }
            }

            vector<int> topological_sort;
            while (!s.empty()) {
                  int node = s.top();
                  s.pop();
                  topological_sort.push_back(node);
            }

            return topological_sort;
      }
};

int main() {
      unordered_map<int, vector<int>> adjacency_list = deserialize();
      Solution solution;
      vector<int> topological_sort = solution.find_topological_sort(adjacency_list);

      cout << "Topological sort -> ";
      for (int& node : topological_sort) {
            cout << node << " ";
      }
      cout << endl;

      return 0;
}
