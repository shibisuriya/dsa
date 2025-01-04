// https://leetcode.com/problems/rotate-list/

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x) {}
};

pair<ListNode *, int> deserialize() {
      string line = "";
      ListNode *head = nullptr, *tail = nullptr;
      getline(cin, line);
      istringstream iss(line);
      int value = 0;
      while (iss >> value) {
            ListNode *node = new ListNode(value);
            if (!head) {
                  head = node;
            } else if (tail) {
                  tail->next = node;
            }
            tail = node;
      }

      int k = 0;
      cin >> k;

      return {head, k};
}

class Solution {
     public:
      ListNode *rotateRight(ListNode *head, int k) {
            if (!head || k == 0) {
                  return head;
            }

            ListNode *first = head, *second = head;

            int size = 0;
            bool end_reached = false;

            for (int i = 0; i < k; i++) {
                  if (first->next) {
                        first = first->next;
                        size++;
                  } else {
                        return rotateRight(head, k % (size + 1));
                  }
            }

            while (first->next) {
                  first = first->next;
                  second = second->next;
            }

            ListNode *new_head = second->next;
            ListNode *new_tail = new_head;

            while (new_tail->next) {
                  new_tail = new_tail->next;
            }

            new_tail->next = head;

            second->next = nullptr;

            return new_head;
      }
};

int main() {
      Solution solution;
      pair<ListNode *, int> input = deserialize();
      ListNode *head = input.first;
      int k = input.second;
      ListNode *new_head = solution.rotateRight(head, k);

      ListNode *tail = new_head;

      cout << "Rotated linked list -> ";
      while (tail) {
            cout << tail->val << " ";
            tail = tail->next;
      }
      cout << endl;

      return 0;
}
