#include <bits/stdc++.h>

#include <cmath>

using namespace std;

pair<vector<int>, vector<int>> parse_input() {
      string line_1 = "";
      string line_2 = "";

      getline(cin, line_1);
      getline(cin, line_2);

      istringstream iss_1(line_1);
      istringstream iss_2(line_2);

      int temp = 0;
      vector<int> a;
      while (iss_1 >> temp) {
            a.push_back(temp);
      }

      temp = 0;
      vector<int> b;

      while (iss_2 >> temp) {
            b.push_back(temp);
      }

      return make_pair(a, b);
}

class Solution {
     public:
      double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int total_size = nums1.size() + nums2.size();
            int mid_point = ceil(total_size / 2.0);

            bool is_odd = true;
            if (total_size % 2 == 0) {
                  is_odd = false;
                  mid_point++;
            }

            int i = 0, j = 0;
            int counter = 1;

            double last_number = 0.0;

            while (i < nums1.size() || j < nums2.size()) {
                  double min_num = 0.0;

                  if (i < nums1.size() && j < nums2.size()) {
                        if (nums1[i] < nums2[j]) {
                              min_num = nums1[i];
                              i++;
                        } else {
                              min_num = nums2[j];
                              j++;
                        }
                  } else if (i < nums1.size()) {
                        min_num = nums1[i];
                        i++;
                  } else {
                        min_num = nums2[j];
                        j++;
                  }

                  if (counter == mid_point) {
                        if (is_odd) {
                              return min_num;
                        } else {
                              return (min_num + last_number) / 2.0;
                        }
                  }
                  counter++;
                  last_number = min_num;
            }
            return 0;
      }
};

int main() {
      Solution sol;
      pair<vector<int>, vector<int>> inputs = parse_input();
      sol.findMedianSortedArrays(inputs.first, inputs.second);

      return 0;
}
