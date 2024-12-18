#include <bits/stdc++.h>

using namespace std;

// The time complexity of `find` is O(n).

void vector_example() {
      vector<int> nums = {3, 2, 1};
      vector<int>::iterator it = find(nums.begin(), nums.end(), 1);
      if (it != nums.end()) {
            cout << "Element found at index " << distance(nums.begin(), it) << endl;
      } else {
            cout << "Element not found";
      }
}

void array_example() {
      int n = 4;
      int nums[] = {1, 2, 3, 4};
      int* ip = find(nums, nums + 4, 4);

      if (ip != nums + n) {
            cout << "Element found at index " << distance(nums, ip) << endl;
      } else {
            cout << "Element not found";
      }
}

int main() {
      //vector_example();
      array_example();
      return 0;
}
