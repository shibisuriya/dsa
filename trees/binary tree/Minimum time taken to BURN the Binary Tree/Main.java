// Amount of Time for Binary Tree to Be Infected
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
// https://www.youtube.com/watch?v=2r5wLmQfD6g&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=31

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

class Main {
  public static void main(String args[]) {
    Scanner lineScanner = new Scanner(System.in);
    String line = lineScanner.nextLine();
    int start = lineScanner.nextInt();
    Scanner scanner = new Scanner(line);
    TreeNode root = null;
    Queue<TreeNode> q = new LinkedList<>();
    root = new TreeNode(scanner.nextInt());
    q.add(root);
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
    System.out.println("Answer " + solution.amountOfTime(root, start));
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
  private HashMap<Integer, TreeNode> parentMap = new HashMap<>();
  private TreeNode start = null;
  private Set<Integer> visited = new TreeSet<>();

  private void createParentMap(TreeNode root, int start) {
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);
    parentMap.put(root.val, null);
    while (!q.isEmpty()) {
      int length = q.size();
      for (int i = 0; i < length; i++) {
        TreeNode node = q.poll();
        if (node.val == start) this.start = node;
        if (node.left != null) {
          q.add(node.left);
          parentMap.put(node.left.val, node);
        }
        if (node.right != null) {
          q.add(node.right);
          parentMap.put(node.right.val, node);
        }
      }
    }
  }

  public int amountOfTime(TreeNode root, int start) {
    createParentMap(root, start);
    Queue<TreeNode> q = new LinkedList<>();
    q.add(this.start);
    int time = 0;
    while (!q.isEmpty()) {
      int length = q.size();
      time++;
      for (TreeNode node : q) System.out.print(node.val + " ");
      System.out.println("\n");
      for (int i = 0; i < length; i++) {
        TreeNode node = q.poll();
        visited.add(node.val);
        if (node.left != null && !visited.contains(node.left.val)) {
          q.add(node.left);
          visited.add(node.left.val);
        }
        if (node.right != null && !visited.contains(node.right.val)) {
          q.add(node.right);
          visited.add(node.right.val);
        }
        TreeNode parent = parentMap.get(node.val);
        if (parent != null && !visited.contains(parent.val)) {
          visited.add(parent.val);
          q.add(parent);
        }
      }
    }
    return time - 1;
  }
}
