#include <bits/stdc++.h>

//https://leetcode.com/problems/flood-fill/description/

using namespace std;

class Solution {
     public:
      vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));

            int initial_color = image[sr][sc];

            q.push(make_pair(sr, sc));

            while (!q.empty()) {
                  pair<int, int> pixel = q.front();
                  q.pop();
                  if (!visited[pixel.first][pixel.second] && image[pixel.first][pixel.second] == initial_color) {
                        visited[pixel.first][pixel.second] = true;
                        image[pixel.first][pixel.second] = color;

                        if (pixel.first - 1 >= 0) {
                              // top
                              q.push(make_pair(pixel.first - 1, pixel.second));
                        }

                        if (pixel.second + 1 < image[0].size()) {
                              // right
                              q.push(make_pair(pixel.first, pixel.second + 1));
                        }

                        if (pixel.first + 1 < image.size()) {
                              // bottom
                              q.push(make_pair(pixel.first + 1, pixel.second));
                        }

                        if (pixel.second - 1 >= 0) {
                              // left
                              q.push(make_pair(pixel.first, pixel.second - 1));
                        }
                  }
            }
            return image;
      }
};

int main() {
      Solution solution;

      vector<vector<int>> adjacent_matrix = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
      int sr = 1, sc = 1, color = 2;

      solution.floodFill(adjacent_matrix, sr, sc, color);

      cout << "Image -> " << endl;
      for (vector<int>& row : adjacent_matrix) {
            for (int& cell : row) {
                  cout << cell << " ";
            }
            cout << endl;
      }

      return 0;
}
