#include <bits/stdc++.h>

using namespace std;

class Parser {
     public:
      vector<int> parse() {
            int temp = 0;
            vector<int> x;
            while (cin >> temp) {
                  x.push_back(temp);
            }
            return x;
      }
};
