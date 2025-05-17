// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.TreeMap;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    Queue<Node> q = new LinkedList<>();
    Node root = null;
    if (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      root = new Node(val);
      q.add(root);
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
    System.out.println(Solution.topView(root));
  }
}

class Node {
  int data;
  Node left;
  Node right;

  Node(int data) {
    this.data = data;
    left = null;
    right = null;
  }
}

class NodeWithIndex {
  public Node node;
  public int index;

  NodeWithIndex(Node node, int index) {
    this.node = node;
    this.index = index;
  }
}

class Solution {
  static ArrayList<Integer> topView(Node root) {
    TreeMap<Integer, Integer> map = new TreeMap<>();

    Queue<NodeWithIndex> q = new LinkedList<>();
    q.add(new NodeWithIndex(root, 0));

    while (!q.isEmpty()) {
      int length = q.size();

      for (int i = 0; i < length; i++) {
        NodeWithIndex nodeWithIndex = q.poll();
        Node node = nodeWithIndex.node;
        int index = nodeWithIndex.index;

        if (!map.containsKey(index)) {
          map.put(index, node.data);
        }

        if (node.left != null) q.add(new NodeWithIndex(node.left, index - 1));
        if (node.right != null) q.add(new NodeWithIndex(node.right, index + 1));
      }
    }

    return new ArrayList<Integer>(map.values());
  }
}
