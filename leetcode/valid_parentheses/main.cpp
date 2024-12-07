#include <bits/stdc++.h>

using namespace std;

const unordered_map<char, int> symbols = {{'[', 1}, {'{', 2}, {'(', 3}, {']', -1}, {'}', -2}, {')', -3}};

class Solution {
     public:
      bool isValid(string str) {
            stack<char> s;
            for (char &c : str) {
                  if (symbols.at(c) > 0) {
                        s.push(c);
                  } else {
                        if (s.empty()) {
                              return false;
                        }
                        char top = s.top();
                        if (symbols.at(top) + symbols.at(c) != 0) {
                              return false;
                        }
                        s.pop();
                  }
            }
            return s.empty();
      }
};

int main() {
      Solution sol;
      string i = "";
      cin >> i;
      bool answer = sol.isValid(i);
      cout << "Answer -> " << answer << endl;
      return 0;
}
