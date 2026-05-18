// https://leetcode.com/problems/path-sum/?envType=problem-list-v2&envId=depth-first-search

import java.util.LinkedList;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    String line = null;
    TreeNode root = null;
    Integer targetSum = null;
    LinkedList<TreeNode> q = new LinkedList<>();

    if (scanner.hasNextLine()) {
      line = scanner.nextLine();
    }
    Scanner lineScanner = new Scanner(line);
    if (scanner.hasNextInt()) {
      targetSum = scanner.nextInt();
    }

    if (lineScanner.hasNextInt()) {
      int val = lineScanner.nextInt();
      if (val != -1) {
        root = new TreeNode(val);
        q.push(root);
      }
    }

    while (!q.isEmpty()) {
      TreeNode node = q.poll();
      if (lineScanner.hasNextInt()) {
        Integer val = lineScanner.nextInt();
        if (val != -1) {
          node.left = new TreeNode(val);
          q.add(node.left);
        }
      }
      if (lineScanner.hasNextInt()) {
        Integer val = lineScanner.nextInt();
        if (val != -1) {
          node.right = new TreeNode(val);
          q.add(node.right);
        }
      }
    }
    Solution sol = new Solution();
    System.out.println(sol.hasPathSum(root, targetSum));
    lineScanner.close();
    scanner.close();
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
  public boolean traverse(TreeNode node, int targetSum, int sum) {
    if (node == null) return false;

    if (node.left == null && node.right == null && targetSum == sum + node.val) {
      return true;
    }

    return node.left != null && this.traverse(node.left, targetSum, sum + node.val)
        || node.right != null && this.traverse(node.right, targetSum, sum + node.val);
  }

  public boolean hasPathSum(TreeNode root, int targetSum) {
    return this.traverse(root, targetSum, 0);
  }
}
