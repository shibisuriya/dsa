// https://leetcode.com/problems/binary-tree-inorder-traversal
//
// #hard #revise #revised/1

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    TreeNode root = null;
    Queue<TreeNode> q = new LinkedList<>();
    if (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      if (val != -1) {
        root = new TreeNode(val);
        q.add(root);
      }
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
    solution.inorderTraversal(root);
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
  public List<Integer> inorderTraversal(TreeNode root) {
    TreeNode cur = root;
    ArrayList<Integer> inorder = new ArrayList<>();
    while (cur != null) {
      if (cur.left != null) {
        TreeNode prev = cur.left;
        while (prev.right != null && prev.right != cur) {
          prev = prev.right;
        }
        if (prev.right == cur) {
          prev.right = null;
          inorder.add(cur.val);
          cur = cur.right;
        } else {
          prev.right = cur;
          cur = cur.left;
        }
      } else {
        inorder.add(cur.val);
        cur = cur.right;
      }
    }
    return inorder;
  }
}
