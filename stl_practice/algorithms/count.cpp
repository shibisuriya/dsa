#include <bits/stdc++.h>

using namespace std;

// Time complexity of `count` function is O(n).

void vector_example() {
      vector<int> nums = {1, 2, 3, 3, 3, 3};
      int three_count = count(nums.begin(), nums.end(), 3);
      cout << "Number of times three is preset in the vector " << three_count << endl;
}

void array_example() {
      int n = 6;
      int nums[] = {1, 2, 3, 3, 3, 3};
      int three_count = count(nums, nums + n, 3);
      cout << "Number of times three is preset in the vector " << three_count << endl;
}

int main() {
      // vector_example();
      array_example();

      return 0;
}
