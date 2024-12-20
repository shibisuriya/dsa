#include <bits/stdc++.h>

using namespace std;

class Solution {
     public:
      void sortColors(vector<int>& nums) {
            unordered_map<int, int> count = {{0, 0}, {1, 0}, {2, 0}};

            for (int n : nums) {
                  count[n]++;
            }

            int index = 0;

            for (int color = 0; color < count.size(); color++) {
                  for (int i = 0; i < count[color]; i++) {
                        nums[index] = color;
                        index++;
                  }
            }
      }
};

vector<int> parse_input() {
      int val = 0;
      vector<int> input;
      while (cin >> val) {
            input.push_back(val);
      }
      return input;
}

int main() {
      vector<int> nums = parse_input();

      Solution sol;
      sol.sortColors(nums);

      return 0;
}
