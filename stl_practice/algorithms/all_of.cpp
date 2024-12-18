#include <bits/stdc++.h>

using namespace std;

void vector_example() {
      vector<int> nums = {2, 4, 8};
      bool is_all_even = all_of(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });
      cout << "All numbers are " << (is_all_even ? "even." : "not even.") << endl;
}

void array_example() {
      int n = 3;
      int nums[] = {2, 3, 6};
      bool is_all_even = all_of(nums, nums + 3, [](int x) { return x % 2 == 0; });
      cout << "All numbers are " << (is_all_even ? "even." : "not even.") << endl;
}

int main() {
      // vector_example();
      array_example();
      return 0;
}
