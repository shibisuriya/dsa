#include <bits/stdc++.h>

#include "./input_parser.hpp"
#include "solution.hpp"

using namespace std;

int main() {
      Parser parser;
      vector<int> input = parser.parse();
      Solution solution;

      // ## Predefined size
      // To declare a vector of size 10
      // vector<int> x(10);
      // The size of the vector can be changed during runtime (obiviously by adding and removing elements
      // from it).
      // Use the second argument to supply a default value...
      // vector<int> x(10, 20);
      // This will create a vector of size 10, with all the
      // elements having the value 20.

      // # pop_back
      // To remove the last element from the vector, use `pop_back`.
      // x.pop_back();

      // ## Time complexity
      // Time complexity of both push_back and pop_back is O(1).

      // ## Copying vectors
      // To create a copy of a vector,
      // vector<int> y = x; or auto y = x;
      // Array(s) don't offer this flexibility.
      // If you copy an array into another,
      // int a[10];
      // int b[] = a;
      // The array `pointer a` will be assigned to b...
      // O(n) is the time complexity of copying a vector into another
      // using the `=` (assignment operator).

      // ## Vectors getting copied during function invocation
      // void print_vector (vector<int> a) {}
      // When the function print_vector is invoked with an `int` vector as argument,
      // it only recieves a copy of the vector not the original vector itself...
      // So changing the contents of the vector inside the print_vector function
      // won't have any effect on the original vector...
      // If you are competing, always pass vectors as reference to functions to
      // prevent copying of the vectors (which is an expensive operation).

      solution.print(input);
      return 0;
}
