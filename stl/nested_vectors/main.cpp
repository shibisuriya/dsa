#include <bits/stdc++.h>

#include "./input_parser.hpp"
#include "solution.hpp"

using namespace std;

int main() {
      Parser parser;
      vector<vector<int>> input = parser.parse();

      Solution solution;
      solution.print(input);
}
