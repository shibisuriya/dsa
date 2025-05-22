// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner lineScanner = new Scanner(System.in);
    String line = lineScanner.nextLine();
    Scanner scanner = new Scanner(line);
    Queue<TreeNode> queue = new LinkedList<>();
    TreeNode root = null;
    if (scanner.hasNextInt()) {
      root = new TreeNode(scanner.nextInt());
      queue.add(root);
    }
    while (!queue.isEmpty()) {
      TreeNode node = queue.poll();

      if (scanner.hasNextInt()) {
        int val = scanner.nextInt();
        if (val != -1) node.left = new TreeNode(val);
        queue.add(node.left);
      }

      if (scanner.hasNextInt()) {
        int val = scanner.nextInt();
        if (val != -1) node.right = new TreeNode(val);
        queue.add(node.right);
      }
    }
    Solution solution = new Solution();
    int p = lineScanner.nextInt();
    int q = lineScanner.nextInt();
    System.out.println(solution.lowestCommonAncestor(root, new TreeNode(p), new TreeNode(q)).val);
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

class Solution {
  private ArrayList<Integer> pPath = new ArrayList<>();
  private ArrayList<Integer> qPath = new ArrayList<>();

  public void recurse(TreeNode node, TreeNode p, TreeNode q, ArrayList<Integer> path) {
    if (node == null) return;

    path.add(node.val);

    if (node.val == p.val) {
      pPath = new ArrayList<>(path);
    }

    if (node.val == q.val) {
      qPath = new ArrayList<>(path);
    }

    if (node.left != null) {
      recurse(node.left, p, q, path);
      path.remove(path.size() - 1);
    }

    if (node.right != null) {
      recurse(node.right, p, q, path);
      path.remove(path.size() - 1);
    }
  }

  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    recurse(root, p, q, new ArrayList<Integer>());
    Integer result = null;
    for (int i = 0, j = 0; i < pPath.size() && j < qPath.size(); i++, j++) {
      if (pPath.get(i) == qPath.get(j)) result = pPath.get(i);
    }

    return new TreeNode(result);
  }
}
