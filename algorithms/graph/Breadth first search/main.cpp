#include <bits/stdc++.h>

using namespace std;

// Time complexity is,
// O(n) + O(2E)
// where 'n' is the number of node present in the graph since we have to
// atleast visit a node ones.
// And 'E' is the number of edges/connections present in the graph. Since a node
// can connect exactly 2 nodes, the time complexity is O(n) (outter while loop) + O(2E) (inner for loop).

unordered_map<int, vector<int>> deserialize() {
      string line = "";
      unordered_map<int, vector<int>> adjacency_list;
      while (getline(cin, line)) {
            istringstream iss(line);
            int vertex = 0, line = 0;
            iss >> vertex;
            while (iss >> line) {
                  adjacency_list[vertex].push_back(line);
            }
      }
      return adjacency_list;
}

class Solution {
     public:
      vector<int> graph_bfs(unordered_map<int, vector<int>> adjecency_list) {
            queue<int> q;
            q.push(1);                                              // Starting the traversal from  node 1.
            vector<bool> visited(adjecency_list.size() + 1, false); // visited[0] will go to waste, but it is okay!
            vector<int> bfs;
            while (!q.empty()) {
                  int node = q.front();
                  q.pop();

                  if (!visited[node]) {
                        bfs.push_back(node);
                        visited[node] = true;

                        vector<int> lines = adjecency_list[node];
                        for (int& line : lines) {
                              q.push(line);
                        }
                  }
            }
            return bfs;
      }
};

int main() {
      unordered_map<int, vector<int>> adjacency_list = deserialize();
      Solution solution;
      vector<int> bfs = solution.graph_bfs(adjacency_list);

      cout << "BFS -> ";
      for (int& vertex : bfs) {
            cout << vertex << " ";
      }
      cout << endl;
      return 0;
}
