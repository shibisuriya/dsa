#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next, *prev;
};

ListNode *deserialize() {
      int val = 0;
      ListNode *head = nullptr, *tail = nullptr;
      while (cin >> val) {
            ListNode *node = new ListNode();
            node->val = val;
            if (!head) {
                  head = node;
            } else if (tail) {
                  node->prev = tail;
                  tail->next = node;
            }
            tail = node;
      }
      return head;
}

int main() {
      ListNode *head = deserialize();
      ListNode *i = head;

      cout << "Forward -> ";

      while (i->next) {
            cout << i->val << " ";
            i = i->next;
      }
      cout << "and " << i->val << endl;

      cout << "Backward -> ";

      while (i->prev) {
            cout << i->val << " ";
            i = i->prev;
      }
      cout << "and " << i->val << endl;

      return 0;
}
