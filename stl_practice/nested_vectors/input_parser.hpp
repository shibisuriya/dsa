#include <bits/stdc++.h>

#include <sstream>

using namespace std;

class Parser {
     public:
      vector<vector<int>> parse() {
            string line = "";
            vector<vector<int>> input;
            while (getline(cin, line)) {
                  istringstream iss(line);
                  int x = 0;
                  vector<int> temp;
                  while (iss >> x) {
                        temp.push_back(x);
                  }
                  input.push_back(temp);
            }
            return input;
      }
};
