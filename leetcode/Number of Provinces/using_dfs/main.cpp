#include <bits/stdc++.h>

using namespace std;

class Solution {
     private:
      vector<vector<int>> adjacency_matrix;
      vector<bool> visited;

      void traverse(int node) {
            if (this->visited[node]) {
                  return;
            }

            this->visited[node] = true;

            for (int i = 0; i < this->adjacency_matrix[node].size(); i++) {
                  if (adjacency_matrix[node][i] == 1) {
                        traverse(i);
                  }
            }
      }

     public:
      int findCircleNum(vector<vector<int>>& isConnected) {
            // assuming the graph starts with a 0 node not a 1 node.
            this->adjacency_matrix = isConnected;
            this->visited = vector<bool>(isConnected.size(), false);

            int number_of_provinces = 0;

            for (int i = 0; i < this->adjacency_matrix.size(); i++) {
                  if (!this->visited[i]) {
                        traverse(i);
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

            vector<int> edges;
            int edge = 0;
            while (iss >> edge) {
                  edges.push_back(edge);
            }
            adjacency_matrix.push_back(edges);
      }

      return adjacency_matrix;
}

int main() {
      vector<vector<int>> adjacency_matrix = deserialize();

      Solution sol;
      int number_of_provinces = sol.findCircleNum(adjacency_matrix);
      cout << "Number of provinces -> " << number_of_provinces << endl;

      return 0;
}
