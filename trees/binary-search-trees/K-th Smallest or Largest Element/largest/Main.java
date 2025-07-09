// https://leetcode.com/problems/kth-smallest-element-in-a-bst
//
// Have used Morris traversal algorithm (inorder)...
//
// Kth largest node = (n - k)th smallest...
//
// Inorder traversal of a BST gives all the nodes in a ascending sorted order.

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class main {
  public static void main(String arggs[]) {
    Scanner lineScanner = new Scanner(System.in);
    String line = lineScanner.nextLine();
    Scanner scanner = new Scanner(line);
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
    int k = lineScanner.nextInt();
    int kthLargest = solution.kthLargest(root, k);
    System.out.println(kthLargest);
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
  public int kthLargest(TreeNode root, int k) {
    TreeNode cur = root;

    int count = 0;

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

    return inorder.get(inorder.size() - k);
  }
}
