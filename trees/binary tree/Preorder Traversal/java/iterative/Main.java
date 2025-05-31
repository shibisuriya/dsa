// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

// Preorder traversal
// Root -> Left -> Right

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

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
    List<Integer> solution = new Solution().preorderTraversal(root);
    for (Integer item : solution) System.out.print(item + "  ");
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
  List<Integer> solution = new ArrayList<>();

  public List<Integer> preorderTraversal(TreeNode root) {
    Stack<TreeNode> s = new Stack<>();
    List<Integer> solution = new ArrayList<>();
    if (root != null) {
      s.add(root);
    }
    while (!s.isEmpty()) {
      TreeNode node = s.pop();
      solution.add(node.val);
      if (node.right != null) s.push(node.right);
      if (node.left != null) s.push(node.left);
    }
    return solution;
  }
}
