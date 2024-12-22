#include <bits/stdc++.h>

#include <queue>

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

      if (input.size() && input[0] == -1) {
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
      int maxDepth(TreeNode* root) {
            int depth = 0;
            if (!root) {
                  return depth;
            }

            queue<TreeNode*> q;
            q.push(root);

            while (!q.empty()) {
                  int size = q.size();
                  for (int i = 0; i < size; i++) {
                        TreeNode* node = q.front();
                        q.pop();

                        if (node->left) {
                              q.push(node->left);
                        }

                        if (node->right) {
                              q.push(node->right);
                        }
                  }
                  depth++;
            }

            return depth;
      }
};

int main() {
      TreeNode* root = deserialize();
      Solution solution;
      int depth = solution.maxDepth(root);

      cout << "Depth -> " << depth << endl;

      return 0;
}
