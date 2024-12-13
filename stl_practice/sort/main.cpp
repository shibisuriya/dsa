#include <bits/stdc++.h>

using namespace std;

void sort_array() {
      int nums[4] = {1, 4, 6, 2};

      sort(nums, nums + 4);

      for (int &n : nums) {
            cout << n << " ";
      }
      cout << endl;

      int nums_2[5] = {5, 4, 3, 2, 1};

      sort(nums_2 + 2, nums_2 + 5); // sort from the second element till the last element.

      for (int &n : nums_2) {
            cout << n << " ";
      }
      cout << endl;

      // STL's sort function is implemented using intro sort.
      // Intro sort is a combination of quick sort, heap sort & insertion sort.
      // Intro sort is believed to be the best sorting alogrithm in the world currently.
}

void sort_string_vector() {
      vector<string> a = {"abc", "ab", "a"};
      sort(a.begin(), a.end());
      cout << "a -> ";
      for (string s : a) {
            cout << s << " ";
      }
      cout << endl;
}

void sort_vector() {
      vector<int> a = {5, 4, 3, 2, 1};
      sort(a.begin(), a.end());
      cout << "a -> " << endl;
      for (int &num : a) {
            cout << num << " ";
      }
      cout << endl;
}

void sort_struct() {
      struct A {
            int age;
            string name;
      };

      vector<A> a = {{10, "Shibi"}, {20, "suriya"}};

      // sort(a.begin(), a.end()); // won't compile!

      cout << "a -> ";
      for (A &s : a) {
            cout << s.age << " " << s.name << endl;
      }
      cout << endl;
}

int main() {
      // sort_array();
      // sort_vector();
      // sort_string_vector();
      sort_struct();
      return 0;
}
