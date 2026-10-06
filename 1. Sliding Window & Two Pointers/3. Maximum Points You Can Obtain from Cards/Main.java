// ## Problem
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Main {}

class Solution {
  public int maxScore(int[] cardPoints, int k) {
    int sum = 0, maxSum = 0;

    for (int i = 0; i < k; i++) {
      sum += cardPoints[i];
    }

    maxSum = sum;

    for (int i = k - 1, j = cardPoints.length - 1; i >= 0; i--, j--) {
      sum -= cardPoints[i];
      sum += cardPoints[j];

      if (sum > maxSum) {
        maxSum = sum;
      }
    }

    return maxSum;
  }
}
