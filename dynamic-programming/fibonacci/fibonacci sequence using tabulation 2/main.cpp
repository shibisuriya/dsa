#include <bits/stdc++.h>

using namespace std;

/*
 * Time complexity is O(n).
 * Space complexity is 2.
 */

class Solution {
      int prev_1 = 0;
      int prev_2 = 1;

     public:
      int find_fibonacci(int n) {
            if (n == 1) {
                  return prev_1;
            } else if (n == 2) {
                  return prev_2;
            };

            for (int i = 2; i < n; i++) {
                  int next = prev_1 + prev_2;
                  prev_1 = prev_2;
                  prev_2 = next;
            }

            return prev_2;
      }
};

int main() {
      int val;
      while (cin >> val) {
            Solution sol;
            int answer = sol.find_fibonacci(val);
            cout << answer << endl;
      }

      return 0;
}
