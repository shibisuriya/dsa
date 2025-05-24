// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner linerScanner = new Scanner(System.in);
    String line = linerScanner.nextLine();
    int targetVal = linerScanner.nextInt();
    int k = linerScanner.nextInt();
    TreeNode target = null;

    Scanner scanner = new Scanner(line);
    TreeNode root = null;
    Queue<TreeNode> q = new LinkedList<>();
    if (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      root = new TreeNode(val);
      q.add(root);
      if (val == targetVal) target = root;
    }
    while (!q.isEmpty()) {
      TreeNode node = q.poll();

      if (scanner.hasNextInt()) {
        int val = scanner.nextInt();
        if (val != -1) {
          node.left = new TreeNode(val);
          q.add(node.left);
          if (val == targetVal) target = node.left;
        }
      }

      if (scanner.hasNextInt()) {
        int val = scanner.nextInt();
        if (val != -1) {
          node.right = new TreeNode(val);
          q.add(node.right);
          if (val == targetVal) target = node.right;
        }
      }
    }

    Solution solution = new Solution();
    System.out.println(solution.distanceK(root, target, k));
  }
}

class NodeWithParent {
  public TreeNode node;
  public TreeNode parent;

  public void NodeWithParent(TreeNode node, TreeNode parent) {
    this.node = node;
    this.parent = parent;
  }
}

class Solution {
  private HashMap<Integer, TreeNode> parents = new HashMap<>();
  private HashSet<Integer> visited = new HashSet<>();

  private void createParentMap(TreeNode root) {
    // Assuming 'val' of every node is unique.
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);
    parents.put(root.val, null);
    while (!q.isEmpty()) {
      int length = q.size();
      for (int i = 0; i < length; i++) {
        TreeNode node = q.poll();
        if (node.left != null) {
          parents.put(node.left.val, node);
          q.add(node.left);
        }
        if (node.right != null) {
          parents.put(node.right.val, node);
          q.add(node.right);
        }
      }
    }
    System.out.println(parents);
  }

  public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
    createParentMap(root);
    Queue<TreeNode> q = new LinkedList<>();
    q.add(target);

    for (int i = 0; i < k; i++) {
      int length = q.size();
      for (int j = 0; j < length; j++) {
        TreeNode node = q.poll();
        if (node.left != null && !visited.contains(node.left.val)) {
          q.add(node.left);
          visited.add(node.left.val);
        }
        if (node.right != null && !visited.contains(node.right.val)) {
          q.add(node.right);
          visited.add(node.right.val);
        }
        TreeNode parent = parents.get(node.val);
        if (parent != null && !visited.contains(parent.val)) {
          System.out.println("parent -> " + parent.val);
          q.add(parent);
          visited.add(parent.val);
        }
        visited.add(node.val);
      }
    }

    List<Integer> result = new ArrayList<>();
    for (TreeNode node : q) result.add(node.val);
    return result;
  }
}

class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;

  TreeNode(int x) {
    val = x;
  }
}
