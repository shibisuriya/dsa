import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

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
  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    List<List<Integer>> result = new ArrayList<>();
    if (root == null) return result;

    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);
    boolean leftToRight = true;

    while (!q.isEmpty()) {
      int size = q.size();
      List<Integer> list = new ArrayList<>();
      for (int i = 0; i < size; i++) {
        TreeNode node = q.poll();
        list.add(node.val);
        if (node.left != null) q.add(node.left);
        if (node.right != null) q.add(node.right);
      }
      if (!leftToRight) list = list.reversed();
      leftToRight = !leftToRight;
      result.add(list);
    }

    return result;
  }
}
