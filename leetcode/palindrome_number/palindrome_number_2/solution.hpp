#include <bits/stdc++.h>

using namespace std;

class Solution {
     public:
     public:
      bool isPalindrome(int x) {
            // int can be -ve.
            // int can be 0.
            // int can be +ve.
            // int can be single digit.
            // int ending with 0.

            if (x >= 0 && x < 10) {
                  return true;
            }

            if (x < 0 || x % 10 == 0) {
                  return false;
            }

            int y = x;
            int reverse = 0;

            // Intuition: When the number of digits present in reverse is more
            // than the number of digits present in 'x' the middle point
            // of x has been reached.

            do {
                  reverse = reverse * 10 + y % 10;
                  y = y / 10;
            } while (reverse < y);

            return y == reverse || y == reverse / 10;
      }
};
