#include <bits/stdc++.h>

using namespace std;

class Solution {
     private:
      void print_vector(vector<int> vec) {
            cout << "Vector -> ";
            for (int v : vec) {
                  cout << v << " ";
            }
            cout << endl;
      }

     public:
      void print(vector<vector<int>> vec) {
            for (vector<int> v : vec) {
                  print_vector(v);
            }
      }
};
