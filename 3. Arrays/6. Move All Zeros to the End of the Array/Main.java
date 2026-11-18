// https://leetcode.com/problems/move-zeroes/description/

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    List<Integer> arr = new ArrayList<>();

    Scanner scanner = new Scanner(System.in);

    while (scanner.hasNextInt()) {
      arr.add(scanner.nextInt());
    }

    scanner.close();

    int i = 0, j = 1;

    while (j < arr.size()) {
      if (arr.get(i) != 0) {
        i++;
      } else if (arr.get(i) == 0 && arr.get(j) != 0) {
        int temp = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, temp);
        i++;
      }

      j++;
    }

    System.out.println(arr);
  }
}
