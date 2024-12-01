#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
};

void populate(TreeNode* parent) {
      string pos = "";
      int val = 0;

      if (cin >> pos && cin >> val) {
            TreeNode* child = new TreeNode();
            child->val = val;

            if (pos == "left") {
                  parent->left = child;
                  populate(child);
            } else if (pos == "right") {
                  parent->right = child;
                  populate(child);
            } else {
                  throw "Invalid pos " + pos + '.';
            }
      }
}

void print_tree(TreeNode* parent) {
      if (parent->left) {
            print_tree(parent->left);
      }

      if (parent->right) {
            print_tree(parent->right);
      }

      cout << parent->val << " \t" << endl;
}

TreeNode* parse_input() {
      TreeNode* root = new TreeNode();
      int val = 0;
      cin >> val;
      root->val = val;
      populate(root);
      return root;
}

int main() {
      TreeNode* root = parse_input();
      print_tree(root);

      return 0;
}
