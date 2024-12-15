
#include <bits/stdc++.h>

using namespace std;

bool should_i_swap(int a, int b) {
      // ascending order.
      return a > b;
};

void my_sort_2() {
      // my O(n^2) sort...
      vector<int> nums = {5, 3, 4, 8, 1};
      for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                  if (should_i_swap(nums[i], nums[j])) {
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                  }

                  // Or swap(nums[i], nums[j]);
            }
      }

      cout << "nums -> " << endl;
      for (int& num : nums) {
            cout << num << " ";
      }
      cout << endl;
}

int main() {
      my_sort_2();
      return 0;
}
