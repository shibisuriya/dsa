#include <bits/stdc++.h>

using namespace std;

/*
 * Time complexity is O(n).
 * Space complexity is O(n).
 */

class Solution {
      vector<int> dp;

     public:
      Solution() {
            dp.push_back(0); // for 0.
            dp.push_back(1); // for 1.
      }

      int find_fibonacci(int n) {
            if (dp.size() >= n) {
                  return dp[n - 1];
            }

            for (int i = 2; i < n; i++) {
                  dp[i] = dp[i - 2] + dp[i - 1];
            }

            return dp[n - 1];
      }
};

int main() {
      Solution sol;

      int val;
      while (cin >> val) {
            int answer = sol.find_fibonacci(val);
            cout << answer << endl;
      }

      return 0;
}
