#include <bits/stdc++.h>

using namespace std;

vector<int> parse_input() {
      int val = 0;
      vector<int> input;
      while (cin >> val) {
            input.push_back(val);
      }
      return input;
}

struct TreeNode {
      int val;
      TreeNode *left, *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* construct_tree(vector<int> input) {
      if (input.empty() || input[0] == -1) {
            return nullptr;
      }

      queue<TreeNode*> q;
      int i = 1;
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
      vector<int> input = parse_input();
      cout << "Input -> ";
      for (int& i : input) {
            cout << i << " ";
      }
      cout << endl;

      TreeNode* root = construct_tree(input);

      return 0;
}
