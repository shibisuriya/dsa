#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode* next;
};

ListNode* deserialize() {
      ListNode *head = nullptr, *tail = nullptr;
      int val = 0;
      while (cin >> val) {
            ListNode* node = new ListNode();
            node->val = val;
            if (!head) {
                  head = node;
            } else if (tail) {
                  tail->next = node;
            }
            tail = node;
      }
      return head;
}

int main() {
      ListNode* head = deserialize();
      ListNode* i = head;

      cout << "Linked list -> ";
      while (i) {
            cout << i->val << " ";
            i = i->next;
      }
      cout << endl;

      return 0;
}
