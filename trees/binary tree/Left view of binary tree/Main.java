// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    Queue<TreeNode> q = new LinkedList<>();
    TreeNode root = null;
    if (scanner.hasNextInt()) {
      root = new TreeNode(scanner.nextInt());
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
    System.out.println(solution.rightSideView(root));
  }
}

class Solution {
  ArrayList<Integer> leftView(Node root) {
    if (root == null) return new ArrayList<Integer>();

    Queue<Node> q = new LinkedList<>();

    q.add(root);

    ArrayList<Integer> result = new ArrayList<>();

    while (!q.isEmpty()) {
      int length = q.size();
      result.add(q.peek().data);

      for (int i = 0; i < length; i++) {
        Node node = q.poll();

        if (node.left != null) q.add(node.left);
        if (node.right != null) q.add(node.right);
      }
    }

    return result;
  }
}

class Node {
  int data;
  Node left, right;

  Node(int item) {
    data = item;
    left = right = null;
  }
}
