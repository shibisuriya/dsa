// https://leetcode.com/problems/minimum-depth-of-binary-tree/?envType=problem-list-v2&envId=depth-first-search

import java.util.LinkedList;
import java.util.Scanner;

public class Main {
  public static void main(String args[]) {
    TreeNode root = null;
    Scanner scanner = new Scanner(System.in);
    String line = null;
    if (scanner.hasNextLine()) {
      line = scanner.nextLine();
    }
    Scanner lineScanner = new Scanner(line);
    LinkedList<TreeNode> q = new LinkedList<>();
    if (lineScanner.hasNextInt()) {
      Integer val = lineScanner.nextInt();
      if (val != -1) {
        root = new TreeNode(val);
        q.add(root);
      }
    }
    while (!q.isEmpty()) {
      TreeNode node = q.poll();
      if (lineScanner.hasNextInt()) {
        int val = lineScanner.nextInt();
        if (val != -1) {
          node.left = new TreeNode(val);
          q.push(node.left);
        }
      }
      if (lineScanner.hasNextInt()) {
        int val = lineScanner.nextInt();
        if (val != -1) {
          node.right = new TreeNode(val);
          q.push(node.right);
        }
      }
    }
    lineScanner.close();
    scanner.close();
    Solution sol = new Solution();
    System.out.println(sol.minDepth(root));
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
  private int min(int a, int b) {
    return a < b ? a : b;
  }

  private int traverse(TreeNode node, int depth) {
    if (node == null) return depth;

    if ((node.left == null && node.right == null)) {
      return depth + 1;
    }

    if (node.left != null && node.right == null) {
      return traverse(node.left, depth + 1);
    }

    if (node.right != null && node.left == null) {
      return traverse(node.right, depth + 1);
    }

    return this.min(this.traverse(node.left, depth + 1), this.traverse(node.right, depth + 1));
  }

  public int minDepth(TreeNode root) {
    return this.traverse(root, 0);
  }
}
