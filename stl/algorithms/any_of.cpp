#include <bits/stdc++.h>

using namespace std;

void array_example() {
      int n = 3;
      int nums[] = {1, 3, 5};
      bool is_any_even = any_of(nums, nums + n, [](int x) { return x % 2 == 0; });
      cout << (is_any_even ? "Atleast one element is even..." : "No element is even!");
}

void vector_example() {
      vector<int> nums = {1, 3, 2};
      bool is_any_even = any_of(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });
      cout << (is_any_even ? "Atleast one element is even..." : "No element is even!");
}

int main() {
      // vector_example();
      array_example();
}
