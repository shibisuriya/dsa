#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
};

class Solution {
     public:
      bool hasCycle(ListNode *head) {
            ListNode *fast = head, *slow = head;
            while (fast && fast->next) {
                  fast = fast->next->next;
                  slow = slow->next;

                  if (fast == slow) {
                        return true;
                  }
            }
            return false;
      }
};

int main() {
      Solution sol;
      ListNode *h = nullptr;
      sol.hasCycle(h);

      return 0;
}
