// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

// Post order traversal
// Left -> Right -> Root

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    TreeNode root = null;
    Queue<TreeNode> q = new LinkedList<>();
    if (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      if (val != -1) {
        root = new TreeNode(val);
        q.add(root);
      }
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
    List<Integer> solution = new Solution().postorderTraversal(root);
    for (Integer item : solution) System.out.print(item + "  ");
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
  List<Integer> solution = new ArrayList<>();

  public List<Integer> postorderTraversal(TreeNode root) {
    Stack<TreeNode> s1 = new Stack<>();
    Stack<TreeNode> s2 = new Stack<>();
    if (root != null) s1.push(root);
    while (!s1.isEmpty()) {
      TreeNode node = s1.pop();
      if (node.left != null) s1.push(node.left);
      if (node.right != null) s1.push(node.right);
      s2.push(node);
    }
    List<Integer> solution = new ArrayList<>();
    while (!s2.isEmpty()) {
      TreeNode node = s2.pop();
      solution.add(node.val);
    }
    return solution;
  }
}
