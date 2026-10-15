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

    for (int i = 1; i < nums.size(); i++) {
      for (int j = i; j > 0 && nums.get(j - 1) > nums.get(j); j--) {
        int temp = nums.get(j - 1);
        nums.set(j - 1, nums.get(j));
        nums.set(j, temp);
      }
    }

    System.out.println(nums);
  }
}
