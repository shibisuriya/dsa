// https://leetcode.com/problems/surrounded-regions/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
     private:
      vector<vector<bool>> invalid_region;
      vector<vector<char>>* board;

      void bfs(int i, int j) {
            if ((*board)[i][j] == 'X') {
                  return;
            }
            if ((*board)[i][j] == 'O' && !invalid_region[i][j]) {
                  invalid_region[i][j] = true;

                  // top
                  if (i - 1 >= 0 && (*board)[i - 1][j] == 'O') {
                        bfs(i - 1, j);
                  }

                  // left
                  if (j - 1 >= 0 && (*board)[i][j - 1] == 'O') {
                        bfs(i, j - 1);
                  }

                  // right
                  if (i + 1 < (*board).size() && (*board)[i + 1][j] == 'O') {
                        bfs(i + 1, j);
                  }

                  if (j + 1 < (*board)[0].size() && (*board)[i][j + 1] == 'O') {
                        bfs(i, j + 1);
                  }
            }
      }

     public:
      void solve(vector<vector<char>>& board) {
            this->invalid_region = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
            this->board = &board;

            // top & bottom
            for (int i = 0; i < board[0].size(); i++) {
                  bfs(0, i);
                  bfs(board.size() - 1, i);
            }

            // left & right
            for (int i = 0; i < board.size(); i++) {
                  bfs(i, board[0].size() - 1);
                  bfs(i, 0);
            }

            for (int i = 0; i < board.size(); i++) {
                  for (int j = 0; j < board[0].size(); j++) {
                        if (!this->invalid_region[i][j] && board[i][j] == 'O') {
                              board[i][j] = 'X';
                        }
                  }
            }
      }
};

int main() {
      Solution solution;
      vector<vector<char>> board = {
          {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

      solution.solve(board);

      return 0;
}
