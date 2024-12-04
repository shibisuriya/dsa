#include <bits/stdc++.h>

using namespace std;

void comparing_complex_datatypes() {
      // Complex datatypes such as pairs and vectors can be compared.
      pair<int, int> a, b;
      a = {1, 2};
      b = {3, 4};

      cout << " a < b = " << (a < b) << endl;

      pair<int, int> c, d;

      c = {1, 2};
      d = {1, 3};

      cout << " c < d = " << (c < d) << endl;
      // Checks 1 < 1 (both are equal), checks next element...
      // 2 < 3 == true so c < d...

      vector<int> e, f;

      e = {1, 2, 3, 4, 5};
      f = {1, 2, 3, 4, 6};

      cout << " e < f = " << (e < f) << endl;
      // Checks 1 < 1, equal, checks next element.
      // Then 2 < 2, equal, checks next element.
      // 3 < 3, equal, checks next element.
      // 4 < 4, equal, checks next element.
      // 5 < 6 == true, so e < f == true

      // Note: `a < e` is an invalid expression, because we are comparing items of pair<int, int> and vector<int>.
      // cout << (a < e) << endl;
}

int main() {
      comparing_complex_datatypes();
      // Since, map & set are implemented using red black tree, complex datatypes such as pair<int, int>, vector<int>, etc. can be
      // used as keys... Only the dataypes which have support for `relational operators` can be used as keys for maps and sets,
      // maps and sets keep their keys sorted and they expect their keys to support comparison operators. A list of items is typically sorted
      // by comparing items present in the list with each other.

      // Unordered maps and unordered sets in C++ do not allow using complex datatypes as keys by default, even if the datatype
      // supports comparison operators, because they are implemented using hash tables rather than red-black trees. To use a
      // custom or complex datatype as a key in unordered_map or unordered_set, you need to first define a custom hash function.
      return 0;
}
