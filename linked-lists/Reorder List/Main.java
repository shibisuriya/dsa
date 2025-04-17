// https://leetcode.com/problems/reorder-list/description/

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);

    ListNode head = null, neck = null;
    while (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      ListNode node = new ListNode(val);
      if (head == null) {
        head = node;
        neck = node;
      } else {
        neck.next = node;
      }
      neck = node;
    }

    Solution solution = new Solution();
    solution.reorderList(head);

    ListNode node = head;

    while (node != null) {
      System.out.println(node.val);
      node = node.next;
    }
  }
}

class ListNode {
  int val;
  ListNode next;

  ListNode() {}

  ListNode(int val) {
    this.val = val;
  }

  ListNode(int val, ListNode next) {
    this.val = val;
    this.next = next;
  }
}

class Solution {
  Queue<ListNode> queue;

  ListNode tail;
  boolean endReached;

  private void recurse(ListNode node) {
    queue.add(node);
    if (node.next != null) {
      recurse(node.next);
    }

    ListNode first = queue.poll();

    if (endReached) {
      return;
    }

    if (first == node) {
      // odd number of nodes in linked list.
      endReached = true;
      tail.next = first;
      first.next = null;
      return;
    } else if (first.next == node) {
      // even number of nodes in linked list.
      endReached = true;
      tail.next = first;
      first.next = node;
      node.next = null;
      return;
    }

    if (tail != null) {
      tail.next = first;
    }

    first.next = node;

    tail = node;
  }

  public void reorderList(ListNode head) {
    queue = new ArrayDeque<>();
    endReached = false;
    recurse(head);
  }
}
