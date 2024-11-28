#include <bits/stdc++.h>

#include <utility>

using namespace std;

pair<vector<int>, int> parse_input() {
      string line = "";
      getline(cin, line);
      istringstream iss(line);
      int temp = 0;
      vector<int> nums;
      while (iss >> temp) {
            nums.push_back(temp);
      }
      int target = 0;
      cin >> target;

      return make_pair(nums, target);
}

class Solution {
     public:
      vector<int> twoSum(vector<int>& nums, int target) {
            for (int i = 0; i < nums.size() - 1; i++) {
                  for (int j = i + 1; j < nums.size(); j++) {
                        if (nums[i] + nums[j] == target) {
                              return vector<int>{i, j};
                        }
                  }
            }
            return vector<int>{};
      }
};

int main() {
      Solution solution;
      pair<vector<int>, int> inputs = parse_input();
      vector<int> answer = solution.twoSum(inputs.first, inputs.second);

      cout << "Answer => ";
      for (int a : answer) {
            cout << a << " ";
      }
      cout << endl;

      return 0;
}
