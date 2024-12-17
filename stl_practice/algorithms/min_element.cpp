#include <bits/stdc++.h>

using namespace std;

// Time complexity is O(n)...

void vector_example() {
      vector<int> nums = {5, 4, 3, 2, 1};
      vector<int>::iterator min = min_element(nums.begin(), nums.end());
      cout << "Min element -> " << *min << endl;

      nums = {};
      min = min_element(nums.begin(), nums.end());
      // If the min element is not found then a pointer to the next element of the
      // last element is returned...
      if (min != nums.end()) {
            cout << "Min element -> " << *min << endl;
      }
}

void array_example() {
      int n = 5;
      int nums[] = {5, 4, 3, 2, 1};
      int *min = min_element(nums, nums + n);
      cout << "Min element -> " << *min << endl;

      int nums_2[] = {};
      min = min_element(nums_2, nums_2);
      // If the min element is not found then a pointer to the next element of the
      // last element is returned...
      if (min != nums_2) {
            cout << "Min element -> " << *min << endl;
      }
}

int main() {
      // vector_example();
      array_example();
      return 0;
}
