#include <bits/stdc++.h>

using namespace std;

class Solution {
     private:
     public:
      int findCircleNum(vector<vector<int>>& isConnected) {
            vector<bool> visited(isConnected.size(), false);
            int number_of_provinces = 0;

            for (int i = 0; i < visited.size(); i++) {
                  if (!visited[i]) {
                        queue<int> q;
                        q.push(i);
                        while (!q.empty()) {
                              int node = q.front();
                              q.pop();
                              visited[node] = true;

                              for (int j = 0; j < isConnected[node].size(); j++) {
                                    if (isConnected[node][j] && !visited[j]) {
                                          q.push(j);
                                    }
                              }
                        }
                        number_of_provinces++;
                  }
            }
            return number_of_provinces;
      }
};

vector<vector<int>> deserialize() {
      string line = "";
      vector<vector<int>> adjacency_matrix;
      while (getline(cin, line)) {
            istringstream iss(line);
            int edge = 0;
            vector<int> edges;
            while (iss >> edge) {
                  edges.push_back(edge);
            }
            adjacency_matrix.push_back(edges);
      }
      return adjacency_matrix;
}

int main() {
      Solution solution;
      vector<vector<int>> adjacency_matrix = deserialize();
      int number_of_provinces = solution.findCircleNum(adjacency_matrix);
      cout << "NUmber of provinces -> " << number_of_provinces << endl;
      return 0;
}
