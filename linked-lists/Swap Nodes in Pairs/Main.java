import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);

    ListNode head = null, neck = null;

    while (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      ListNode node = new ListNode(val);

      if (neck != null) {
        neck.next = node;
      } else {
        head = node;
      }
      neck = node;
    }

    Solution solution = new Solution();
    head = solution.swapPairs(head);

    ListNode node = head;

    System.out.println();
    while (node != null) {
      System.out.println(node.val);
      node = node.next;
    }
  }
}

class Solution {

  private ListNode recurse(
      ListNode firstNode, ListNode secondNode, ListNode thirdNode, ListNode prev) {
    secondNode.next = firstNode;

    if (prev != null) {
      prev.next = secondNode;
    }

    if (thirdNode != null && thirdNode.next != null) {
      recurse(thirdNode, thirdNode.next, thirdNode.next.next, firstNode);
    } else {
      firstNode.next = thirdNode;
    }

    return secondNode;
  }

  public ListNode swapPairs(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }

    return recurse(head, head.next, head.next.next, null);
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
