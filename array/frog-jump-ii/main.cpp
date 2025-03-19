//https://leetcode.com/problems/frog-jump-ii/description

#include <bits/stdc++.h>

using namespace std;

class Solution {
     public:
      int maxJump(vector<int>& stones) {
            if (stones.size() == 2) {
                  return abs(stones[0] - stones[1]);
            }

            int current = 0;
            int next = 2;
            int max = 0;

            while (next < stones.size()) {
                  int size = abs(stones[current++] - stones[next++]);
                  if (size > max) {
                        max = size;
                  }
            }
            return max;
      }
};

int main() {
      vector<int> input;
      int val;
      while (cin >> val) {
            input.push_back(val);
      }

      Solution solution;
      int answer = solution.maxJump(input);
      cout << answer;

      return 0;
}
