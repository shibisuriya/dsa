#include <bits/stdc++.h>

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
            unordered_map<int, int> num_map;
            for (int i = 0; i < nums.size(); i++) {
                  if (num_map.count(nums[i])) {
                        return {num_map.at(nums[i]), i};
                  } else {
                        num_map.insert({target - nums[i], i});
                  }
            }
            return {};
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
