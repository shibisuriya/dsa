#include <iostream>

#include "input_parser.h"

using namespace std;

class Solution {
     public:
      vector<int> twoSum(string a, int target) { return vector<int>{1, 2, 3}; }
};

int main() {
      Solution solution;
      Parser parser;
      pair<string, int> inputs = parser.parse();
      vector<int> answer = solution.twoSum(inputs.first, inputs.second);
      for (int a : answer) {
            cout << a << " ";
      }

      return 0;
}
