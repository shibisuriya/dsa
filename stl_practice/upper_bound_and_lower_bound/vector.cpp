#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

void vector_upper_bound_example() {
      vector<int> nums = {4, 5, 5, 7, 8, 25};

      const int x = 4;
      vector<int>::iterator ub = upper_bound(nums.begin(), nums.end(), x);
      if (ub == nums.end()) {
            cout << x << " was not found!";
      } else {
            cout << "Upper bound -> " << *ub << endl;
      }
}

void vector_lower_bound_example() {
      vector<int> nums = {4, 5, 5, 7, 8, 25};

      const int x = 25;
      vector<int>::iterator lb = lower_bound(nums.begin(), nums.end(), x);
      if (lb == nums.end()) {
            cout << x << " was not found!";
      } else {
            cout << "Lower bound -> " << *lb << endl;
      }
}

int main() {
      //vector_upper_bound_example();
      vector_lower_bound_example();
      return 0;
}
