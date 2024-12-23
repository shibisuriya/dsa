#include <iostream>

#include "./input_parser.h"

using namespace std;

int main() {
      Parser parser;
      vector<int> input = parser.parse();
      // C++ will automatically determine the data type of the iterator below...
      for (auto i : input) {
            // Note that the variable 'i' holds a
            // copy of an element present in the 'input' vector and not
            // the element itself...
            // Which means, if you mutate the value stored in 'i', the elements stored
            // in 'input' will remain unaffected...

            // If your intention is to mutate the elements present in 'input'... Use reference...
            // for(auto &i: input) {}
            cout << i << " ";
      }
      cout << input.size();
      return 0;
}
