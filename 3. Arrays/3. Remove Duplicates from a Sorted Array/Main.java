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

    removeDuplicates(arr);

    System.out.print(arr);
  }

  public static void removeDuplicates(List<Integer> arr) {
    if (arr.size() <= 1) return;

    int i = 1, j = 1;

    while (j < arr.size()) {
      if (arr.get(i - 1) != arr.get(j)) {
        arr.set(i, arr.get(j));
        i++;
      }
      j++;
    }

    while (i < arr.size()) {
      arr.set(i, null);
      i++;
    }
  }
}
