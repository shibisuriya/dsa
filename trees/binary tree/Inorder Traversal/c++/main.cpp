// https://leetcode.com/problems/binary-tree-inorder-traversal

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left, *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
     private:
      vector<int> list;

     public:
      vector<int> inorderTraversal(TreeNode *root) {
            if (!root) {
                  return list;
            }
            inorderTraversal(root->left);

            list.push_back(root->val);

            inorderTraversal(root->right);

            return list;
      }
};

TreeNode *deserialize() {
      int val = 0;
      vector<int> input;
      while (cin >> val) {
            input.push_back(val);
      }

      if (input.empty() || input[0] == -1) {
            return nullptr;
      }

      int i = 1;
      queue<TreeNode *> q;
      TreeNode *root = new TreeNode(input[0]);
      q.push(root);

      while (i < input.size() && !q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            if (input[i] != -1) {
                  TreeNode *left = new TreeNode(input[i]);
                  node->left = left;
                  q.push(left);
            }
            i++;

            if (i < input.size() && input[i] != -1) {
                  TreeNode *right = new TreeNode(input[i]);
                  node->right = right;
                  q.push(right);
            }
            i++;
      }
      return root;
}

int main() {
      TreeNode *root = deserialize();
      Solution solution;
      vector<int> answer = solution.inorderTraversal(root);

      cout << "Answer -> ";
      for (int &num : answer) {
            cout << num << " ";
      }
      cout << endl;
      return 0;
}
