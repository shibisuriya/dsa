#include <bits/stdc++.h>

using namespace std;

class Parser {
     public:
      vector<int> parse() {
            vector<int> v;
            int temp = 0;
            while (cin >> temp) {
                  v.push_back(temp);
            }
            return v;
      }
};
