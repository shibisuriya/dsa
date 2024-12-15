#include <bits/stdc++.h>

using namespace std;

bool should_i_swap(pair<int, int> a, pair<int, int> b) {
      if (a.first != b.first) {
            return a.first > b.first;
      } else {
            return a.second < b.second;
      }
};

void my_sort_2() {
      // my O(n^2) sort...
      vector<pair<int, int>> nums = {{9, 2}, {8, 2}, {8, 3}, {7, 1}};
      for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                  if (should_i_swap(nums[i], nums[j])) {
                        pair<int, int> temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                  }

                  // Or swap(nums[i], nums[j]);
            }
      }

      cout << "nums -> " << endl;
      for (pair<int, int>& num : nums) {
            cout << num.first << ", " << num.second << endl;
            ;
      }
      cout << endl;
}

int main() {
      my_sort_2();
      return 0;
}
