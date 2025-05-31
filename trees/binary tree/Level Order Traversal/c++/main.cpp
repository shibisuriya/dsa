// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left, *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* deserialize() {
      int val = 0;
      vector<int> input;
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
      vector<vector<int>> levelOrder(TreeNode* root) {
            if (!root) {
                  return {};
            }
            queue<TreeNode*> q;
            q.push(root);
            vector<vector<int>> levels;
            while (!q.empty()) {
                  vector<int> level;
                  int size = q.size();
                  for (int i = 0; i < size; i++) {
                        TreeNode* node = q.front();
                        q.pop();
                        level.push_back(node->val);
                        if (node->left) {
                              q.push(node->left);
                        }
                        if (node->right) {
                              q.push(node->right);
                        }
                  }
                  levels.push_back(level);
            }
            return levels;
      }
};

int main() {
      TreeNode* root = deserialize();
      Solution solution;
      vector<vector<int>> levels = solution.levelOrder(root);

      cout << "Answer -> " << endl;
      for (vector<int> level : levels) {
            for (int& num : level) {
                  cout << num << " ";
            }
            cout << endl;
      }
      cout << endl;

      return 0;
}
