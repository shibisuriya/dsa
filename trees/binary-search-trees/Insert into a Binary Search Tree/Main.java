// https://leetcode.com/problems/insert-into-a-binary-search-tree/

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner lineScanner = new Scanner(System.in);
    String line = lineScanner.nextLine();
    Scanner scanner = new Scanner(line);
    TreeNode root = null;
    Queue<TreeNode> q = new LinkedList<>();
    if (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      root = new TreeNode(val);
      if (val != -1) q.add(root);
    }
    while (!q.isEmpty()) {
      TreeNode node = q.poll();

      if (scanner.hasNextInt()) {
        int val = scanner.nextInt();
        if (val != -1) {
          node.left = new TreeNode(val);
          q.add(node.left);
        }
      }

      if (scanner.hasNextInt()) {
        int val = scanner.nextInt();
        if (val != -1) {
          node.right = new TreeNode(val);
          q.add(node.right);
        }
      }
    }

    int val = lineScanner.nextInt();
    Solution solution = new Solution();

    solution.insertIntoBST(root, val);
  }
}

class Solution {
  public TreeNode insertIntoBST(TreeNode root, int val) {
    if (root == null) return new TreeNode(val);
    TreeNode node = root;
    while (true) {
      if (val < node.val) {
        if (node.left == null) {
          node.left = new TreeNode(val);
          return root;
        } else node = node.left;
      } else {
        if (node.right == null) {
          node.right = new TreeNode(val);
          return root;
        } else node = node.right;
      }
    }
  }
}

class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;

  TreeNode() {}

  TreeNode(int val) {
    this.val = val;
  }

  TreeNode(int val, TreeNode left, TreeNode right) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}
