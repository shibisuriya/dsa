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

  void recurse(TreeNode node, int depth) {
    if (md < depth) {
      md = depth;
    }

    if (node.left != null) recurse(node.left, depth + 1);

    if (node.right != null) recurse(node.right, depth + 1);
  }

  private int md = 0;

  public int maxDepth(TreeNode root) {

    if (root == null) return md;

    recurse(root, 1);

    return md;
  }
}
