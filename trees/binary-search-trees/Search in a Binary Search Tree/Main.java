// https://leetcode.com/problems/search-in-a-binary-search-tree/description/

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
    int val = lineScanner.nextInt();
    System.out.println(solution.searchBST(root, val));
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
  public TreeNode searchBST(TreeNode root, int val) {
    if (root == null) return null;

    if (root.val == val) return root;

    return val < root.val ? searchBST(root.left, val) : searchBST(root.right, val);
  }
}
