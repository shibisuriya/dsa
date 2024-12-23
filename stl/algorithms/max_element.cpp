#include <bits/stdc++.h>

using namespace std;

// Time complexity of max_element is O(n).

void vector_example() {
      vector<int> nums = {5, 4, 3, 2, 1};
      vector<int>::iterator max = max_element(nums.begin(), nums.end());
      cout << "Max element -> " << *max << endl;

      nums = {};
      max = max_element(nums.begin(), nums.end());
      // If the max element is not found then a pointer to the next element of the
      // last element is returned...
      if (max != nums.end()) {
            cout << "Max. element -> " << *max << endl;
      }
}

void array_example() {
      int n = 5;
      int nums[] = {5, 4, 3, 2, 1};
      int *max = max_element(nums, nums + n);
      cout << "Max element -> " << *max << endl;

      int nums_2[] = {};
      max = max_element(nums_2, nums_2);
      // If the max element is not found then a pointer to the next element of the
      // last element is returned...
      if (max != nums_2) {
            cout << "Max. element -> " << *max << endl;
      }
}

int main() {
      // vector_example();
      array_example();
      return 0;
}
