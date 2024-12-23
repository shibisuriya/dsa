#include <bits/stdc++.h>

using namespace std;

class Parser {
     public:
      pair<int, string> parse() {
            int roll_number = 0;
            string name;
            cin >> roll_number;
            cin >> name;
            // pair<int, string> input = {roll_number, name};
            // return input;
            // return make_pair(roll_number, name);
            return pair<int, string>{roll_number, name};
      }
};
