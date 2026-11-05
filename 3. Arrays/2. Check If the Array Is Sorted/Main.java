import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);

    List<Integer> arr = new ArrayList<>();

    while (scanner.hasNextInt()) {
      arr.add(scanner.nextInt());
    }

    scanner.close();

    System.out.print(isArraySorted(arr));
  }

  public static boolean isArraySorted(List<Integer> arr) {
    if (arr.size() <= 1) return true;

    for (int i = 1; i < arr.size(); i++) {
      if (arr.get(i - 1) > arr.get(i)) return false;
    }

    return true;
  }
}
