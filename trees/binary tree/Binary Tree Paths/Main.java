// https://www.youtube.com/watch?v=fmflMqVOC7k&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=26
// https://leetcode.com/problems/binary-tree-paths

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
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
    System.out.println(solution.binaryTreePaths(root));
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

  private ArrayList<String> paths = new ArrayList<>();

  private void inorderTraversal(TreeNode root, List<Integer> path) {
    if (root == null) return;

    path.add(root.val);

    if (root.left == null && root.right == null) {
      String newPath = "";
      for (int node : path) newPath = newPath != "" ? newPath + "->" + node : node + "";
      paths.add(newPath);
    }

    inorderTraversal(root.left, path);
    inorderTraversal(root.right, path);

    path.remove(path.size() - 1);
  }

  public List<String> binaryTreePaths(TreeNode root) {
    inorderTraversal(root, new ArrayList<Integer>());
    return paths;
  }
}
