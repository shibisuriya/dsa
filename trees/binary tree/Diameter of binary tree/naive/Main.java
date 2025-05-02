// Naive - O(n^2)
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    Queue<TreeNode> q = new LinkedList<>();

    TreeNode root = null;
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
          TreeNode left = new TreeNode(val);
          node.left = left;
          q.add(left);
        }
      }

      if (scanner.hasNextInt()) {
        int val = scanner.nextInt();
        if (val != -1) {
          TreeNode right = new TreeNode(val);
          node.right = right;
          q.add(right);
        }
      }
    }

    Solution solution = new Solution();
    System.out.println(solution.diameterOfBinaryTree(root));
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
  private int findDepth(TreeNode node) {
    if (node == null) return 0;

    if (node.left == null && node.right == null) return 1;

    int lh = node.left != null ? findDepth(node.left) : 0;
    int rh = node.right != null ? findDepth(node.right) : 0;

    return 1 + Math.max(lh, rh);
  }

  private int diameter = 0;

  public int diameterOfBinaryTree(TreeNode node) {
    if (node == null) return 0;

    int ld = node.left != null ? findDepth(node.left) : 0;
    int rd = node.right != null ? findDepth(node.right) : 0;
    int length = 1 + ld + rd;
    diameter = Math.max(diameter, length);

    diameterOfBinaryTree(node.left);
    diameterOfBinaryTree(node.right);

    return diameter - 1;
  }
}
