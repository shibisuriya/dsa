#include <bits/stdc++.h>

using namespace std;

class Parser {
     public:
      pair<string, int> parse() {
            string line;
            getline(cin, line);

            int num;
            cin >> num;

            return make_pair(line, num);
      }
};
