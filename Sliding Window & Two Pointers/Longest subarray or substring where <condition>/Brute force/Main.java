import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    int k = 18;
    int maxSum = 0;

    ArrayList<Integer> arr = new ArrayList<>();
    while (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      arr.add(val);
    }

    int from = 0;
    int to = 0;

    // I was not able to write the loop written below easily... #practice.
    for (int i = 0; i < arr.size(); i++) {
      for (int j = i; j < arr.size(); j++) {
        int sum = 0;

        System.out.print("-> ");
        for (int z = i; z <= j; z++) {
          System.out.print(arr.get(z) + ", ");
          sum += arr.get(z);
          if (sum >= k) {
            break;
          }
        }
        System.out.println();

        if (sum > maxSum && sum <= k) {
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
