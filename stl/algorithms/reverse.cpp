#include <bits/stdc++.h>

using namespace std;

// The time complexity of 'reverse' is O(n).

void vector_example() {
      vector<int> nums = {3, 2, 1};
      cout << "Before reverse  -> ";
      for (int& n : nums) {
            cout << n << " ";
      }
      cout << endl;

      reverse(nums.begin(), nums.end());
      cout << "After reverse  -> ";
      for (int& n : nums) {
            cout << n << " ";
      }
      cout << endl;
}

void string_example() {
      string str = "abcd";
      cout << "Before reverse -> ";
      for (char& c : str) {
            cout << c << " ";
      }
      cout << endl;

      reverse(str.begin(), str.end());

      cout << "After reverse -> ";
      for (char& c : str) {
            cout << c << " ";
      }
      cout << endl;
}

void array_example() {
      int n = 4;
      int nums[] = {4, 3, 2, 1};
      cout << "Before reverse -> ";
      for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
      }
      cout << endl;
      reverse(nums, nums + n);
      cout << "After reverse -> ";
      for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
      }
      cout << endl;
}

int main() {
      // vector_example();
      // string_example();
      array_example();
      return 0;
}
