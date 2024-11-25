#include <iostream>

#include "./input_parser.h"

using namespace std;

int main() {
      Parser parser;
      vector<int> input = parser.parse();
      vector<int>::iterator it;
      for (it = input.begin(); it < input.end(); it++) {
            // (*it).first <==> it->first
            cout << *it << " ";
      }
      cout << input.size();
      return 0;
}
