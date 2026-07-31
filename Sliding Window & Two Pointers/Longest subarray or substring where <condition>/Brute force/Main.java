import java.util.ArrayList;
import java.util.Scanner;

// Time complexity  O(N)
// Space complexity O(1)

public class Main {
  public static void main(String args[]) {
    Scanner lineScanner = new Scanner(System.in);
    String line = lineScanner.nextLine();
    Scanner scanner = new Scanner(line);

    ArrayList<Integer> arr = new ArrayList<>();

    while (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      arr.add(val);
    }

    int k = lineScanner.nextInt();
    int maxSum = 0;
    int from = 0;
    int to = 0;

    lineScanner.close();
    scanner.close();

    // for (int i = 0; i < arr.size(); i++) {
    //   for (int j = i; j < arr.size(); j++) {
    //     int sum = 0;
    //     for (int z = i; z <= j; z++) {
    //       sum += arr.get(z);
    //     }
    //     if (sum > maxSum) {
    //       maxSum = sum;
    //       from = i;
    //       to = j;
    //     }
    //   }
    // }

    for (int i = 0; i < arr.size(); i++) {
      int sum = 0;
      for (int j = i; j < arr.size(); j++) {
        sum += arr.get(j);
        if (sum > k) {
          break;
        }
        if (sum > maxSum) {
          maxSum = sum;
          from = i;
          to = j;
        }
      }
    }

    System.out.print("Answer -> ");
    for (int i = from; i <= to; i++) {
      System.out.print(arr.get(i) + ", ");
    }
  }
}
