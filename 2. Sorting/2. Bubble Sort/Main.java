import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    List<Integer> nums = new ArrayList<>();

    Scanner scanner = new Scanner(System.in);

    while (scanner.hasNextInt()) {
      nums.add(scanner.nextInt());
    }

    scanner.close();

    boolean isSwapped = false;

    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = i + 1; j < nums.size() - i; j++) {
        if (nums.get(j) < nums.get(i)) {
          int temp = nums.get(i);
          nums.set(i, nums.get(j));
          nums.set(j, temp);
          isSwapped = true;
        }
      }

      // Array is already sorted, time complexity
      // is O(n) for this case.
      if (isSwapped) break;
    }

    System.out.println(nums);
  }
}
