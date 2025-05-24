// Didn't find this question in 'leetcode', using this
// 'https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/'
// instead.

// Problem Statement:
//
// Given a Binary Tree, convert the value of its nodes to follow the Children Sum Property.
// The Children Sum Property in a binary tree states that for every node, the sum of its children's
// values (if they exist) should be equal to the node's value. If a child is missing, it is
// considered as having a value of 0.

// - The node values can be increased by any positive integer any number of times, but decrementing
// any node value is not allowed.
// - A value for a NULL node can be assumed as 0.
// - We cannot change the structure of the given binary tree.

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
  private static void printTree(TreeNode root, int indent) {
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);
    while (!q.isEmpty()) {
      int length = q.size();
      for (int i = 0; i < length; i++) {
        TreeNode node = q.poll();
        System.out.print(node.val + " ");
        if (node.left != null) q.add(node.left);
        if (node.right != null) q.add(node.right);
      }
      System.out.println("\n");
    }
  }

  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    Queue<TreeNode> q = new LinkedList<>();
    TreeNode root = null;
    if (scanner.hasNextInt()) {
      root = new TreeNode(scanner.nextInt());
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

    // printTree(root, 0);

    Solution solution = new Solution();
    TreeNode head = solution.childrenSumProperty(root);
    System.out.println("HEAD " + head);
    printTree(head, 0);
  }
}

class Solution {
  public TreeNode childrenSumProperty(TreeNode root) {
    if (root == null) return null;

    int val = root.val;
    int leftVal = root.left != null ? root.left.val : 0;
    int rightVal = root.right != null ? root.right.val : 0;

    int sum = leftVal + rightVal;

    if (val > sum) {
      if (root.left != null) root.left.val = val;
      if (root.right != null) root.right.val = val;
    }

    TreeNode left = childrenSumProperty(root.left);
    TreeNode right = childrenSumProperty(root.right);

    if (left != null && right != null) root.val = left.val + right.val;
    else if (right != null) root.val = right.val;
    else if (left != null) root.val = left.val;

    return root;
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
