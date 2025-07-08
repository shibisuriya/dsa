// https://leetcode.com/problems/delete-node-in-a-bst/

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner lineScanner = new Scanner(System.in);
    String line = lineScanner.nextLine();
    Scanner scanner = new Scanner(line);
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
    int key = lineScanner.nextInt();
    Solution sol = new Solution();
    sol.deleteNode(root, key);
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
  private int key;

  private TreeNode findRightLeftNode(TreeNode root) {
    TreeNode node = root;
    while (node.right != null) {
      node = node.right;
    }
    return node;
  }

  private void dfs(TreeNode node) {
    if (node == null) return;

    if (node.left != null && node.left.val == this.key) {
      TreeNode parent = node;
      node = node.left; // node to be removed
      TreeNode rightNode = node.right;

      if (node.left != null) {
        parent.left = node.left;
        TreeNode rightLeftNode = findRightLeftNode(parent.left);
        rightLeftNode.right = rightNode;
      } else if (node.right != null) parent.left = node.right;
      else parent.left = null;
      return;
    } else if (node.right != null && node.right.val == this.key) {
      TreeNode parent = node;
      node = node.right; // node to be removed
      TreeNode rightNode = node.right;

      if (node.left != null) {
        parent.right = node.left;
        TreeNode rightLeftNode = findRightLeftNode(parent.right);
        rightLeftNode.right = rightNode;
      } else if (node.right != null) parent.right = node.right;
      else parent.right = null;
      return;
    }
    dfs(node.left);
    dfs(node.right);
  }

  public TreeNode deleteNode(TreeNode root, int key) {
    if (root == null) return null;
    if (root.val == key && root.left == null && root.right == null) return null;

    if (root.val == key) {
      if (root.left != null) {
        TreeNode rightLeftNode = findRightLeftNode(root.left);
        rightLeftNode.right = root.right;
        root = root.left;
        return root;
      } else {
        return root.right;
      }
    }

    this.key = key;

    dfs(root);

    return root;
  }
}
