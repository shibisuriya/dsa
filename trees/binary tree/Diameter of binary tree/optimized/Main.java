// O(n)
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    TreeNode root = null;

    Queue<TreeNode> q = new LinkedList<>();
    if (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      root = new TreeNode(val);
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
    solution.diameterOfBinaryTree(root);
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
  private int diameter = 0;

  private int height(TreeNode node) {
    if (node == null) return 0;

    int lh = height(node.left);
    int rh = height(node.right);

    int path = lh + rh;
    diameter = Math.max(diameter, path);

    return Math.max(lh, rh) + 1;
  }

  public int diameterOfBinaryTree(TreeNode root) {
    height(root);
    return diameter;
  }
}
