#include <bits/stdc++.h>

#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
};

pair<ListNode *, ListNode *> parse() {
      string line_1, line_2;
      vector<pair<ListNode *, ListNode *>> inputs;
      ListNode *head_1 = nullptr;
      ListNode *head_2 = nullptr;

      while (getline(cin, line_1) && getline(cin, line_2)) {
            istringstream iss_1(line_1);
            ListNode *node_1 = nullptr;
            int temp = 0;
            while (iss_1 >> temp) {
                  ListNode *node = new ListNode();
                  node->val = temp;
                  if (!head_1) {
                        head_1 = node;
                  } else if (node_1) {
                        node_1->next = node;
                  }
                  node_1 = node;
            }

            istringstream iss_2(line_2);
            ListNode *node_2 = nullptr;
            temp = 0;

            while (iss_2 >> temp) {
                  ListNode *node = new ListNode();
                  node->val = temp;
                  if (!head_2) {
                        head_2 = node;
                  } else if (node_2) {
                        node_2->next = node;
                  }
                  node_2 = node;
            }
      }

      return make_pair(head_1, head_2);
}

class Solution {
     public:
      ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode *head_1 = l1;
            cout << "L1 -> ";
            while (head_1) {
                  cout << head_1->val << " ";
                  head_1 = head_1->next;
            }
            cout << endl;
      }
};

int main() {
      Solution solution;
      pair<ListNode *, ListNode *> inputs = parse();
      solution.addTwoNumbers(inputs.first, inputs.second);

      return 0;
}
