// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner lineScanner = new Scanner(System.in);
    String line = lineScanner.nextLine();
    Scanner scanner = new Scanner(line);
    Queue<Node> q = new LinkedList<>();
    Node root = null;
    if (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      if (val != -1) {
        root = new Node(val);
        q.add(root);
      }
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
    Tree tree = new Tree();
    int key = lineScanner.nextInt();
    System.out.println(tree.findCeil(root, key));
  }
}

class Node {
  int data;
  Node left, right;

  Node(int data) {
    this.data = data;
    left = right = null;
  }
}

class Solution {
  public static int floor(Node root, int x) {
    Node head = root;
    int floor = -1;
    if (head == null) return floor;
    while (head != null) {
      if (head.data == x) return head.data;
      if (x > head.data) floor = head.data;
      if (x < head.data) {
        head = head.left;
      } else {
        head = head.right;
      }
    }
    return floor;
  }
}
