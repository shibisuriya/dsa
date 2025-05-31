#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left, *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* deserialize() {
      vector<int> input;
      int val;
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

class Solution {
     public:
      vector<int> preorderTraversal(TreeNode* root) {
            vector<int> list;

            if (!root) {
                  return list;
            }

            stack<TreeNode*> s;
            s.push(root);

            while (!s.empty()) {
                  TreeNode* node = s.top();
                  s.pop();
                  list.push_back(node->val);

                  // push 'right' first...
                  if (node->right) {
                        s.push(node->right);
                  }

                  if (node->left) {
                        s.push(node->left);
                  }
            }
            return list;
      }
};

int main() {
      TreeNode* root = deserialize();
      Solution sol;
      sol.preorderTraversal(root);
      return 0;
}
