// https://www.youtube.com/watch?v=fmflMqVOC7k&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=26

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner lineScanner = new Scanner(System.in);
    String line = lineScanner.nextLine();
    int toFind = lineScanner.nextInt();
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

    Solution solution = new Solution();
    System.out.println(solution.rootToNodePath(root, toFind));
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
  ArrayList<Integer> path = new ArrayList<>();

  boolean inorderTraversal(TreeNode node, int toFind) {
    if (node == null) return false;

    path.add(node.val);

    if (node.val == toFind) {
      return true;
    }

    if (inorderTraversal(node.left, toFind) || inorderTraversal(node.right, toFind)) return true;

    path.remove(path.size() - 1);

    return false;
  }

  ArrayList<Integer> rootToNodePath(TreeNode root, int toFind) {
    return inorderTraversal(root, toFind) ? this.path : new ArrayList<>();
  }
}
