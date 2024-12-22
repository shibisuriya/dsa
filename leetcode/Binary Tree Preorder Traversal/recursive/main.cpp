// https://leetcode.com/problems/binary-tree-preorder-traversal

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left, *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
      vector<int> list;

     public:
      vector<int> preorderTraversal(TreeNode* root) {
            if (!root) {
                  return list;
            }

            list.push_back(root->val);

            preorderTraversal(root->left);
            preorderTraversal(root->right);

            return list;
      }
};

TreeNode* deserialize() {
      vector<int> input;
      int val = 0;
      while (cin >> val) {
            input.push_back(val);
      }

      if (input.empty() || input[0] == -1) {
            return nullptr;
      }

      int i = 1;
      queue<TreeNode*> q;
      TreeNode* root = new TreeNode(input[0]);
      q.push(root);

      while (i < input.size() && !q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (input[i] != -1) {
                  TreeNode* left = new TreeNode(input[i]);
                  node->left = left;
                  q.push(left);
            }
            i++;

            if (i < input.size() && input[i] != -1) {
                  TreeNode* right = new TreeNode(input[i]);
                  node->right = right;
                  q.push(right);
            }
            i++;
      }

      return root;
}

int main() {
      TreeNode* root = deserialize();
      Solution sol;
      vector<int> answer = sol.preorderTraversal(root);
      cout << "Answer -> ";
      for (int& a : answer) {
            cout << a << " ";
      }
      cout << endl;
      return 0;
}
