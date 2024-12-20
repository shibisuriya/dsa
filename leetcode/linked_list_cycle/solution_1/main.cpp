#include <bits/stdc++.h>

#include <unordered_set>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
};

class Solution {
     public:
      bool hasCycle(ListNode *head) {
            unordered_set<ListNode *> s;
            ListNode *i = head;
            while (i) {
                  auto it = s.find(i);
                  if (it == s.end()) {
                        s.insert(i);
                  } else {
                        return true;
                  }
                  i = i->next;
            }

            return false;
      }
};

int main() {
      Solution sol;
      ListNode *head = nullptr;
      sol.hasCycle(head);
      return 0;
}
