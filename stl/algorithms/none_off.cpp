#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

void vector_example() {
      vector<int> nums = {1, 5, 3};
      bool is_none_even = none_of(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });
      cout << (is_none_even ? "No element is even!" : "Atleast one element is even!") << endl;
}

void array_example() {
      int n = 3;
      int nums[] = {1, 2, 3};
      bool is_none_even = none_of(nums, nums + n, [](int x) { return x % 2 == 0; });
      cout << (is_none_even ? "No element is even!" : "Atleast one element is even!") << endl;
}

int main() {
      // vector_example();
      array_example();
      return 0;
}
