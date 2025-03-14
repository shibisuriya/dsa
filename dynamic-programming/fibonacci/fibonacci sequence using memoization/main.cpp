#include <bits/stdc++.h>

using namespace std;

class Solution {
     private:
      unordered_map<int, int> dp;

     public:
      int fibonacci(int n) {
            if (n <= 2)
                  return n;

            unordered_map<int, int>::iterator it = dp.find(n);
            if (it != dp.end()) {
                  return it->second;
            }

            int sol = fibonacci(n - 1) + fibonacci(n - 2);
            dp.insert({n, sol});

            return sol;
      }
};

int main() {
      int val;
      Solution solution;

      while (cin >> val) {
            int result = solution.fibonacci(val);
            cout << result << endl;
      }
      return 0;
}
