#include <iostream>

#include "./input_parser.h"
#include "./solution.hpp"

using namespace std;

int main() {
      Parser parser;
      pair<int, string> input = parser.parse();
      Print print;
      print.print(input);
      return 0;
}
