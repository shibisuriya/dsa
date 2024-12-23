
#include <bits/stdc++.h>

using namespace std;

// # STL Maps
// - `Normal maps` keep their keys sorted,
// under the hood they use the `Red black tree` datastructure.
// - If we were to use strings as keys for a map, the keys will be sorted
// in lexicographical order.
// - The time complexity of inserting an item into a map is O(log(n)),
// - The time complexity of inserting an item into a normal map also depends on its key's datatype.
// If the key's datatype is int, then the time complexity of inserting an item into the map is O(log(n)),
// if it is string, then the time complexity would be s.size() * log(n). As mentioned above
// normal maps use the `Red black tree` datastructure under the hood and they keep their keys sorted,
// When a map recieves a request to insert an item inside it, to keep the keys sorted, the map has to traverse to
// an appropriate position in the Red black tree to insert the item. Traversing is done by comparing the
// keys of the map... If the key's datatype is string, the map would end up doing a lot of string comparison operations to
// traverse to an appropriate location before inserting an item, significantly increasing the time complexity...

int plus_plus_operator(map<int, string> m) {
      // # The `++` operator
      // To access the next item of a map using its iterator, use the ++ operator,
      // don't use the `+` operator (binary operator).
      // map<int, string> m;
      // map<int, string>::iterator it = m.begin();
      // it++; // Will point `it` to the next item of the map `m`.
      // it = it+1; // Won't work...

      map<int, string>::iterator it;

      for (it = m.begin(); it != m.end(); it++) {
            cout << it->first << " " << it->second << endl; // or cout << (*it).first << " " << (*it).second << endl;
      }
      // or using `range based loops`.
      // for (auto it : m) {
      //       cout << it->first << " " << it->second << endl;
      // }

      return 0;
}

void find(map<int, string> m, int key) {
      map<int, string>::iterator it = m.find(key); // or auto it = m.find(key);
      // If the key doesn't exist in the map m, the find function will return
      // the m.end()...
      cout << "Value stored at " << it->first << " is " << it->second << endl;
}

void erase(map<int, string> m, int key) {
      m.erase(key); // O(log(n)) time complexity.
      // `erase()` can also accept an iterator of type map<int, string>::iterator.
      // So, to remove the first element of a map, `m.erase(m.begin())`;
}

void clear(map<int, string> m) {
      m.clear(); // Clear the map.
      cout << m.size() << endl;
}

int main() {
      int num = 0;
      string name = "";
      map<int, string> m;

      while (cin >> num && cin >> name) {
            m.insert({num, name}); // or m[num] = name; The time complexity is O(log(n)).
            // Note that the statement `m[num]` is meant for adding/modifying an item
            // in the map... Its not meant for reading the value of an
            // item present in the map using a key, to read the value of an item
            // present in the map using a key, use the find() function.
            // So, the statement `m[num];` (without an assignment operator) will assign the value
            // of "" to the map m's item having key == num...
            // "" because the datatype of the map m is map<int, string>,
            // when a variable of string datatype is declared without initialization it is assigned the default
            // value of "".
      }

      find(m, 5);

      plus_plus_operator(m);
}
