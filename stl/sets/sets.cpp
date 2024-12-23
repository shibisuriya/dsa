#include <bits/stdc++.h>

using namespace std;

// # Set
// - Set is collection of unique elements.
// - A `normal set` stores its elements in a sorted order.
// - Have been implemented using `Red black trees`.
// - Time complexity of adding an item / reading an item from a `normal set` is O(log(n)).

// # Unordered set
// - Time complexity of adding an item / reading an item from an `unordered set` is O(n).
// - Have been implemented using 'hash tables'.
// - Unordered sets can't store values of datatypes that don't have a builtin hash function.
// - Don't keep thier elements in a sorted order.
// - Stores only unique elements.

// # Multiset
// - Multset is a collection of elements.
// - Multisets are implemented using `Red black tree`.
// - A Multiset can store multiple copies of the same element.
// - Time complexity of reading and writing operations on multisets is O(log(n)).
// - Keeps its elements sorted.

void set_example() {
      set<string> s;
      s.insert("c"); // "c" is inserted only 1 time.
      s.insert("c");
      s.insert("b");
      s.insert("a"); // Also a normal set stores its elements in a sorted order.

      auto it = s.find("b"); // using an iterator.
      if (it != s.end()) {
            s.erase(it); // or supply a value, `s.erase("b");`
      }

      cout << "Set -> ";
      for (auto& i : s) {
            cout << i << " ";
      }
      cout << endl;
}

void multiset_example() {
      set<string> s;
      s.insert("c");
      s.insert("c"); // "c" is inserted twice.
      s.insert("b");
      s.insert("a"); // Also a multiset stores its elements in a sorted order.

      auto it = s.find("c"); // using an iterator.
      if (it != s.end()) {
            s.erase(it); // Only removes one instance of "c", iterator 'it' points to this instance of "c".
                         // s.erase("c"); // Removes both instance of "c" from the set.
      }

      cout << "Multiset -> ";
      for (auto& i : s) {
            cout << i << " ";
      }
      cout << endl;
}

int main() {
      set_example();

      return 0;
}
