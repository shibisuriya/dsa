#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

void array_lower_bound_example() {
      // # Lower bound

      // If the element 'x' is present in the array, lower_bound(x) will return a pointer pointing to the
      // first occurrence of x in the array... If x is not present in the array it will return
      // a pointer pointing to the next greater element of x, if the next greater element of x doesn't exist
      // in the array it will return a pointer pointing to the next element of the last element.
      // Examples,
      // array -> 4 5 5 7 8 25
      // lower_bound(5) -> Will return a pointer to the first 5.
      // lower_bound(6) -> Will return a pointer to 7 (next greater element of 6).
      // lower_bound(100) -> Will return a pointer to the next element of 25.

      int n = 6;
      int nums[] = {4, 5, 5, 7, 8, 25}; // note that we have two 5 in this array.
      sort(nums, nums + 6);             // if the array is not sorted the time complexity changes from O(logn) to O(n).
                                        // Where n is the number of elements present in the array.

      int x = 5;
      int *lb = lower_bound(nums, nums + n, x);
      if (lb != lb + n) {
            // if the lower bound is not found, the function returns the pointer to the next element of the last element of the array...
            cout << "Lower bound is -> " << *lb << endl;
      } else {
            cout << x << " was not found";
      }
}

void array_upper_bound_example() {
      // # Upper bound
      // upper_bound(x) will return a pointer pointing to the next greater element of x, if the next greater element of x doesn't exist
      // in the array it will return a pointer pointing to the next element of the last element.
      // Examples,
      // array -> 4 5 5 7 8 25
      // upper_bound(4) -> Will return a pointer to the first occurrence 5 (next greater element of 4).
      // upper_bound(6) -> Will return a pointer to 7 (next greater element of 6).
      // upper_bound(100) -> Will return a pointer to the next element of 25.

      int n = 6;
      int nums[] = {4, 5, 5, 7, 8, 25};

      int x = 4;
      int *ub = upper_bound(nums, nums + n, x);
      if (ub == nums + n) {
            cout << x << " was not found!" << endl;
      } else {
            cout << "Upper bound -> " << *ub << endl;
      }
}

void array_restricted_range_lower_bound() {
      int n = 6;
      int nums[] = {4, 5, 20, 7, 8, 25};

      int x = 8;
      int *lb = lower_bound(nums, nums + 3, x); // Only search within the first three elements of the array.
      if (lb == nums + n) {
            cout << x << " was not found!" << endl;
      } else {
            cout << "Lower bound -> " << *lb << endl;
      }
      // This will print 7 which is the next element of 20...
      // since 8 can't be found within nums and nums + 3, a pointer to the next element of the
      // last element is returned (n+3 + 1)...
}

int main() {
      // array_lower_bound_example();
      // array_upper_bound_example();
      array_restricted_range_lower_bound();

      return 0;
}
