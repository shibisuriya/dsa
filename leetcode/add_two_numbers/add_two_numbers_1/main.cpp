#include <bits/stdc++.h>

#include <sstream>
#include <utility>

using namespace std;

struct ListNode {
      int val;
      ListNode* next;
};

pair<ListNode*, ListNode*> parse_input() {
      string line_1 = "", line_2 = "";

      ListNode *head_1 = nullptr, *head_2 = nullptr;

      while (getline(cin, line_1) && getline(cin, line_2)) {
            istringstream iss_1(line_1);
            int temp = 0;
            ListNode* l1_node = nullptr;
            while (iss_1 >> temp) {
                  ListNode* node = new ListNode();

                  node->val = temp;
                  if (!head_1) {
                        head_1 = node;
                  } else if (l1_node) {
                        l1_node->next = node;
                  }
                  l1_node = node;
            }

            istringstream iss_2(line_2);
            temp = 0;
            ListNode* l2_node = nullptr;
            while (iss_2 >> temp) {
                  ListNode* node = new ListNode();

                  node->val = temp;
                  if (!head_2) {
                        head_2 = node;
                  } else if (l2_node) {
                        l2_node->next = node;
                  }
                  l2_node = node;
            }
      }
      return make_pair(head_1, head_2);
}

class Solution {
     public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* h1 = l1;
            ListNode* h2 = l2;

            ListNode* head = nullptr;
            ListNode* temp = nullptr;
            int carry = 0;

            while (l1 || l2) {
                  int val_1 = 0, val_2 = 0;
                  if (l1) {
                        val_1 = l1->val;
                  }

                  if (l2) {
                        val_2 = l2->val;
                  }
                  int result = val_1 + val_2 + carry;

                  carry = 0;

                  if (result > 9) {
                        carry = result / 10;
                        result = result % 10;
                  }

                  ListNode* node = new ListNode();
                  node->val = result;
                  if (!head) {
                        head = node;
                  } else if (temp) {
                        temp->next = node;
                  }
                  temp = node;

                  if (l1) {
                        l1 = l1->next;
                  }
                  if (l2) {
                        l2 = l2->next;
                  }

                  if (!l1 && !l2 && carry > 0) {
                        ListNode* new_node = new ListNode();
                        new_node->val = carry;
                        temp->next = new_node;
                  }
            }

            return head;
      }
};

int main() {
      pair<ListNode*, ListNode*> inputs = parse_input();

      Solution solution;
      ListNode* h = solution.addTwoNumbers(inputs.first, inputs.second);
      ListNode* t = h;
      while (t) {
            cout << t->val << " ";
            t = t->next;
      }
      cout << endl;
      return 0;
}
