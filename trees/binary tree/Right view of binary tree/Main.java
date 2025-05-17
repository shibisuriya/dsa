// https://leetcode.com/problems/binary-tree-right-side-view/submissions/1636682890/

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

class Main {
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

    Solution solution = new Solution();
    System.out.println(solution.rightSideView(root));
  }
}

class Solution {
  public List<Integer> rightSideView(TreeNode root) {
    if (root == null) return new ArrayList<Integer>();

    Queue<TreeNode> q = new LinkedList<>();

    q.add(root);

    List<Integer> result = new ArrayList<>();

    while (!q.isEmpty()) {
      int length = q.size();
      TreeNode node = null;

      for (int i = 0; i < length; i++) {
        node = q.poll();

        if (node.left != null) q.add(node.left);
        if (node.right != null) q.add(node.right);
      }

      result.add(node.val);
    }

    return result;
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
