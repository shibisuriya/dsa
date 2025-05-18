import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    Node root = null;
    Queue<Node> q = new LinkedList<>();

    if (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      root = new Node(val);
    }

    while (!q.isEmpty()) {
      Node node = q.poll();

      if (scanner.hasNextInt()) {
        int val = scanner.nextInt();
        if (val != -1) {
          node.left = new Node(val);
          q.add(node.left);
        }
      }

      if (scanner.hasNextInt()) {
        int val = scanner.nextInt();
        if (val != -1) {
          node.right = new Node(val);
          q.add(node.right);
        }
      }
    }

    Solution solution = new Solution();
    boolean isSymmetric = solution.isSymmetric(root);
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
  boolean recurse(TreeNode left, TreeNode right) {
    if (left == null && right == null) return true;

    if (left != null && right != null && left.val == right.val) {
      return recurse(left.left, right.right) && recurse(left.right, right.left);
    }

    return false;
  }

  public boolean isSymmetric(TreeNode root) {
    if (root == null) return true;

    return recurse(root.left, root.right);
  }
}
