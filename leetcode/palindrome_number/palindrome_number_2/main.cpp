#include <bits/stdc++.h>

#include "./input_parser.hpp"
#include "solution.hpp"

using namespace std;

int main() {
      Parser parser;
      int input = parser.parse();
      Solution solution;
      bool answer = solution.isPalindrome(input);
      cout << answer;
}
