import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {

    Scanner scanner = new Scanner(System.in);

    List<Integer> nums = new ArrayList<>();

    while (scanner.hasNextInt()) {
      nums.add(scanner.nextInt());
    }

    scanner.close();

    for (int i = 0; i < nums.size() - 1; i++) {

      int minIndex = i;

      for (int j = i + 1; j < nums.size(); j++) {
        if (nums.get(j) < nums.get(i)) minIndex = j;
      }

      int temp = nums.get(i);
      nums.set(i, nums.get(minIndex));
      nums.set(minIndex, temp);
    }

    System.out.println(nums);
  }
}
