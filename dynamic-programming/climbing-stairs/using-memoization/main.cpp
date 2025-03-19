// https://leetcode.com/problems/climbing-stairs/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
     private:
      unordered_map<int, int> map;

     public:
      int climbStairs(int n) {
            if (n <= 1) {
                  return 1;
            }

            unordered_map<int, int>::iterator it = map.find(n);

            if (it != map.end()) {
                  return it->second;
            }

            int result = climbStairs(n - 1) + climbStairs(n - 2);

            map.insert({n, result});

            return result;
      }
};

int main() {
      int val;
      while (cin >> val) {
            Solution solution;
            int result = solution.climbStairs(val);
            cout << result << endl;
      }
}
