// https://leetcode.com/problems/binary-tree-preorder-traversal/description/
//
// #hard #revise

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
    solution.preorderTraversal(root);
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
  public List<Integer> preorderTraversal(TreeNode root) {
    ArrayList<Integer> preorder = new ArrayList<>();
    TreeNode cur = root;
    while (cur != null) {
      if (cur.left != null) {
        TreeNode prev = cur.left;
        while (prev.right != null && prev.right != cur) {
          prev = prev.right;
        }
        if (prev.right == cur) {
          prev.right = null;
          cur = cur.right;
        } else {
          prev.right = cur;
          preorder.add(cur.val);
          cur = cur.left;
        }
      } else {
        preorder.add(cur.val);
        cur = cur.right;
      }
    }
    return preorder;
  }
}
