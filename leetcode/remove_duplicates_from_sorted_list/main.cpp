#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode* next;
};

ListNode* parse_input() {
      ListNode *h = nullptr, *t = nullptr;
      int val = 0;
      while (cin >> val) {
            ListNode* node = new ListNode();
            node->val = val;
            if (!h) {
                  h = node;
            } else {
                  t->next = node;
            }
            t = node;
      }
      return h;
}

class Solution {
     public:
      ListNode* deleteDuplicates(ListNode* head) {
            ListNode* i = head;

            while (i && i->next) {
                  if (i->val == i->next->val) {
                        ListNode* next_next = i->next->next;
                        delete i->next;
                        i->next = next_next;
                  }
                  i = i->next;
            }
            return head;
      }
};

int main() {
      ListNode* head = parse_input();
      Solution sol;
      sol.deleteDuplicates(head);

      return 0;
}
