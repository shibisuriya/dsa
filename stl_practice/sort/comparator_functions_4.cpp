#include <bits/stdc++.h>

using namespace std;

bool should_i_swap(pair<int, int> a, pair<int, int> b) {
      // if you want to swap the elements then return 'false', if you don't want
      // to swap then return true.
      // Instead of thinking about returning a boolean, think about returning a condition / expression.
      if (a.first != b.first) {
            return a.first < b.first;
      } else {
            return a.second > b.second;
      }
}

void my_sort() {
      vector<pair<int, int>> nums = {{9, 2}, {8, 2}, {8, 3}, {7, 1}};

      sort(nums.begin(), nums.end(), should_i_swap);

      // Inbuilt comparator function, greater<pair<int, int>>(), to sort `vector of pairs<int, int>`
      // in decending order...

      cout << "nums -> " << endl;
      for (pair<int, int>& num : nums) {
            cout << num.first << ", " << num.second << endl;
      }
      cout << endl;
}

int main() {
      my_sort();
      return 0;
}
