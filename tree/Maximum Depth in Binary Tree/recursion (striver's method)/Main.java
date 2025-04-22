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
        Integer value = scanner.nextInt();

        if (value != -1) {
          node.left = new TreeNode(value);
          q.add(node.left);
        }
      }

      if (scanner.hasNextInt()) {
        Integer value = scanner.nextInt();
        if (value != -1) {
          node.right = new TreeNode(value);
          q.add(node.right);
        }
      }
    }

    Solution solution = new Solution();
    System.out.println("Answer -> " + solution.maxDepth(root));
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

  public int maxDepth(TreeNode node) {

    if (node == null) return 0;

    int ld = maxDepth(node.left);
    int rd = maxDepth(node.right);

    return 1 + Math.max(ld, rd);
  }
}
