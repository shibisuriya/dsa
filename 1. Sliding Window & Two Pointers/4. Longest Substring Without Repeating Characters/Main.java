// ## Problem
//
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

import java.util.HashMap;
import java.util.Map;

class Main {}

class Solution {
  // Using a set

  // public int lengthOfLongestSubstring(String s) {
  //   int l = 0, r = 0, maxLength = 0;
  //
  //   Set<Character> set = new HashSet<>();
  //
  //   while (r < s.length()) {
  //     while (set.contains(s.charAt(r))) {
  //       set.remove(s.charAt(l));
  //       l++;
  //     }
  //
  //     set.add(s.charAt(r));
  //
  //     int length = r - l + 1;
  //     if (maxLength < length) maxLength = length;
  //
  //     r++;
  //   }
  //
  //   return maxLength;
  // }

  public int lengthOfLongestSubstring(String s) {
    int maxLen = 0, l = 0, r = 0;

    Map<Character, Integer> lastSeenAt = new HashMap<>();

    while (r < s.length()) {

      char c = s.charAt(r);

      if (lastSeenAt.containsKey(c) && lastSeenAt.get(c) >= l) {
        int prevIndex = lastSeenAt.get(c);
        l = prevIndex + 1;
      }

      lastSeenAt.put(c, r);

      int length = r - l + 1;

      if (maxLen < length) maxLen = length;

      r++;
    }

    return maxLen;
  }
}
