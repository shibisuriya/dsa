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

            if (x < 0) {
                  return false;
            }

            if (x == 0) {
                  return true;
            }

            int y = x;
            long reverse = 0;

            do {
                  int last_digit = y % 10;
                  reverse = reverse * 10 + last_digit;
                  y = y / 10;

            } while (y != 0);

            return reverse == x;
      }
};
