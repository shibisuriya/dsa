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
      ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2) {
            ListNode* head = nullptr;
            ListNode* neck = nullptr;

            while (l1 || l2) {
                  ListNode* node = new ListNode();
                  if (l1 && l2) {
                        int val_1 = l1->val;
                        int val_2 = l2->val;

                        node->val = val_1 > val_2 ? l2->val : l1->val;

                        if (val_1 > val_2) {
                              l2 = l2->next;
                        } else {
                              l1 = l1->next;
                        }
                  }

                  else if (l1) {
                        node->val = l1->val;
                        l1 = l1->next;
                  }

                  else if (l2) {
                        node->val = l2->val;
                        l2 = l2->next;
                  }

                  if (!head) {
                        head = node;
                  } else if (neck) {
                        neck->next = node;
                  }

                  neck = node;
            }
            return head;
      }
};

int main() {
      pair<ListNode*, ListNode*> inputs = parse_input();

      Solution solution;
      ListNode* h = solution.mergeTwoSortedList(inputs.first, inputs.second);
      ListNode* t = h;
      while (t) {
            cout << t->val << " ";
            t = t->next;
      }
      cout << endl;
      return 0;
}
