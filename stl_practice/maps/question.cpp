#include <bits/stdc++.h>

// Given n strings, print unique strings in lexiographical order
// with their frequency, N <= 10^5, |S| <= 100.

using namespace std;

int main() {
      string str = "";
      map<string, int> m;
      while (cin >> str) {
            m[str]++;
      }

      for (auto it : m) {
            cout << it.first << " " << it.second << endl;
      }

      return 0;
}
