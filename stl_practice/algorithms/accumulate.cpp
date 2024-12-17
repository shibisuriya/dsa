#include <bits/stdc++.h>

using namespace std;

// Time complexity is O(n).

void vector_example() {
      vector<int> nums = {1, 2, 3, 4, 5};
      int sum = accumulate(nums.begin(), nums.end(), 0); // here 0 is the starting value.
      cout << "Sum -> " << sum << endl;
}

void array_example() {
      int n = 5;
      int nums[] = {1, 2, 3, 4, 5};
      int sum = accumulate(nums, nums + n, 0); // here 0 is the starting value.
      cout << "Sum -> " << sum << endl;
}

int main() {
      // vector_example();
      array_example();

      return 0;
}
