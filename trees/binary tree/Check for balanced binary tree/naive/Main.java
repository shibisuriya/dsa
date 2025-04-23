// Balanced binary tree = for every node, height(left subtree) - height(right subtree) <= 1.
//
// #practice

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// Naive solution

class Main {

  public static void main(String args[]) {

    Scanner scanner = new Scanner(System.in);

    Queue<TreeNode> q = new LinkedList<>();
    TreeNode root = null;
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
          TreeNode left = new TreeNode(val);
          node.left = left;
          q.add(left);
        }
      }

      if (scanner.hasNextInt()) {
        int val = scanner.nextInt();
        if (val != -1) {
          TreeNode right = new TreeNode(val);
          node.right = right;
          q.add(right);
        }
      }
    }

    Solution solution = new Solution();
    System.out.println("Answer -> " + solution.isBalanced(root));
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

class Solution {
  private int findDepth(TreeNode node, int level) {

    int leftDepth = node.left == null ? level : findDepth(node.left, level + 1);

    int rightDepth = node.right == null ? level : findDepth(node.right, level + 1);

    return Math.max(leftDepth, rightDepth);
  }

  public boolean isBalanced(TreeNode node) {
    if (node == null || (node.left == null && node.right == null)) {
      // 1. left node
      // 2. Empty tree
      return true;
    }

    int leftDepth = 0;
    int rightDepth = 0;

    if (node.left != null) {
      leftDepth = findDepth(node.left, 1);
    }

    if (node.right != null) {
      rightDepth = findDepth(node.right, 1);
    }

    if (Math.abs(leftDepth - rightDepth) > 1) return false;

    boolean isLeftBalanced = true;
    if (node.left != null) {
      isLeftBalanced = isBalanced(node.left);
    }

    boolean isRightBalanced = true;
    if (node.right != null) {
      isRightBalanced = isBalanced(node.right);
    }

    if (!isRightBalanced || !isLeftBalanced) {
      return false;
    }

    return true;
  }
}
