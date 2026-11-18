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

    int temp = arr.get(0);

    for (int i = 1; i < arr.size(); i++) {
      arr.set(i - 1, arr.get(i));
    }

    arr.set(arr.size() - 1, temp);

    System.out.println(arr);

    scanner.close();
  }
}
