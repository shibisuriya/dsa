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
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if (root == null) return null;

    boolean found = false;

    if (root.val == p.val || root.val == q.val) found = true;

    TreeNode left = lowestCommonAncestor(root.left, p, q);
    TreeNode right = lowestCommonAncestor(root.right, p, q);

    if (left != null && right != null) return root;

    if (found) return root;

    if (left != null) return left;

    if (right != null) return right;

    return null;
  }
}
