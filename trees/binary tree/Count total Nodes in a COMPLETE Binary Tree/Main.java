// https://leetcode.com/problems/count-complete-tree-nodes/

// What is a complete binary tree?
//
// A complete binary tree is a special type of binary tree where all levels are completely filled
// except for possibly the last level, which is filled from left to right. In other words, the tree
// is as full as possible, with any missing nodes being on the right side of the last level.

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    TreeNode root = null;
    Queue<TreeNode> q = new LinkedList<>();
    if (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      root = new TreeNode(val);
      q.add(root);
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
    Solution solution = new Solution();
    System.out.println("Count: " + solution.countNodes(root));
  }
}

class Solution {
  private int getLeftHeight(TreeNode node) {
    if (node == null) return 0;
    return 1 + getLeftHeight(node.left);
  }

  private int getRightHeight(TreeNode node) {
    if (node == null) return 0;
    return 1 + getRightHeight(node.right);
  }

  public int countNodes(TreeNode root) {
    if (root == null) return 0;

    int lh = getLeftHeight(root.left);
    int rh = getRightHeight(root.right);

    if (lh == rh) {
      return (int) Math.pow(2, lh + 1) - 1;
    }

    return 1 + countNodes(root.left) + countNodes(root.right);
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
