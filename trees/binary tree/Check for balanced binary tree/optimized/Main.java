// #practice

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    Queue<TreeNode> q = new LinkedList<>();
    TreeNode root = null;
    if (scanner.hasNextInt()) {
      int value = scanner.nextInt();
      root = new TreeNode(value);
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
    System.out.println("Answer: " + solution.isBalanced(root));
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
  private int recurse(TreeNode node) {

    if (node == null) return 0;

    if (node.left == null && node.right == null) return 1;

    int lh = recurse(node.left);
    int rh = recurse(node.right);

    if (lh == -1 || rh == -1) return -1;

    return Math.abs(lh - rh) > 1 ? -1 : Math.max(lh, rh) + 1;
  }

  public boolean isBalanced(TreeNode root) {
    return recurse(root) != -1;
  }
}
