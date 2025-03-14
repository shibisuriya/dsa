#include <bits/stdc++.h>

#include <iostream>

using namespace std;

class Solution {
     public:
      int fibonacci(int num = 3) {
            if (num <= 1) {
                  return num;
            }

            return fibonacci(num - 1) + fibonacci(num - 2);
      }
};

int main() {
      Solution solution;

      int val;
      while (cin >> val) {
            int answer = solution.fibonacci(val);
            cout << answer << endl;
      }

      return 0;
}
