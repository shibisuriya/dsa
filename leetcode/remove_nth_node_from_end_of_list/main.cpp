#include <bits/stdc++.h>

#include <map>

using namespace std;

struct ListNode {
      int val;
      ListNode* next;
};

pair<ListNode*, int> parse_input() {
      ListNode *h = nullptr, *t = nullptr;

      string line = "";
      int val = 0;
      int n = 0;

      getline(cin, line);
      cin >> n;

      istringstream iss(line);

      while (iss >> val) {
            ListNode* node = new ListNode();
            node->val = val;
            if (!h) {
                  h = node;
            } else {
                  t->next = node;
            }
            t = node;
      }
      return make_pair(h, n);
}

class Solution {
     public:
      ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *fast = head, *slow = nullptr;
            int counter = 0;
            while (fast) {
                  fast = fast->next;

                  if (slow) {
                        slow = slow->next;
                  }

                  if (counter == n) {
                        slow = head;
                  }

                  counter++;
            }

            if (slow) {
                  ListNode* node_to_remove = slow->next;
                  if (slow->next) {
                        slow->next = slow->next->next;
                  }
                  delete node_to_remove;
            } else {
                  if (head) {
                        return head->next;
                  }
            }

            return head;
      }
};
int main() {
      pair<ListNode*, int> inputs = parse_input();

      ListNode* i = inputs.first;

      cout << "input linked list -> ";
      while (i) {
            cout << i->val << " ";
            i = i->next;
      }
      cout << endl;

      cout << "Input n -> " << inputs.second << endl;

      Solution sol;
      ListNode* h = sol.removeNthFromEnd(inputs.first, inputs.second);

      i = h;
      cout << "Output linked list: ";
      while (i) {
            cout << i->val << " ";
            i = i->next;
      }
      cout << endl;

      return 0;
}
