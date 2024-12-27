// https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
     private:
      void add_neighbors(int i, int j, vector<vector<int>>& grid, queue<pair<pair<int, int>, int>>& q, int minute) {
            if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                  // left
                  q.push(make_pair(make_pair(i, j - 1), minute));
            }

            if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
                  // right
                  q.push(make_pair(make_pair(i, j + 1), minute));
            }

            if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                  // top
                  q.push(make_pair(make_pair(i - 1, j), minute));
            }

            if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
                  // bottom
                  q.push(make_pair(make_pair(i + 1, j), minute));
            }
      }

     public:
      int orangesRotting(vector<vector<int>>& grid) {
            queue<pair<pair<int, int>, int>> q;
            int number_of_fresh_oranges = 0;

            vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));

            // Find all the 'rotten oranges' in the grid.
            // Since the decaying process starts from those cells.
            for (int i = 0; i < grid.size(); i++) {
                  for (int j = 0; j < grid[0].size(); j++) {
                        if (grid[i][j] == 2) {
                              add_neighbors(i, j, grid, q, 1);
                        }
                        if (grid[i][j] == 1) {
                              number_of_fresh_oranges++;
                        }
                  }
            }

            int number_of_oranges_rotten = 0;
            int minutes = 0;

            while (!q.empty()) {
                  int size = q.size();
                  for (int i = 0; i < size; i++) {
                        pair<pair<int, int>, int> orange = q.front();
                        q.pop();
                        pair<int, int> cell = orange.first;
                        int minute = orange.second;

                        if (grid[cell.first][cell.second] == 1 && !visited[cell.first][cell.second]) {
                              grid[cell.first][cell.second] = 2;
                              visited[cell.first][cell.second] = true;
                              number_of_oranges_rotten++;
                              minutes = minute;
                              add_neighbors(cell.first, cell.second, grid, q, minute + 1);
                        }
                  }
            }

            return number_of_oranges_rotten == number_of_fresh_oranges ? minutes : -1;
      }
};

int main() {
      vector<vector<int>> grid = {{2, 2}, {1, 1}, {0, 0}, {2, 0}};

      Solution solution;
      int minutes = solution.orangesRotting(grid);
      cout << "Minutes -> " << minutes;

      return 0;
}
