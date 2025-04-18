import java.util.ArrayList;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    ArrayList<Integer> arr = new ArrayList<>();
    Scanner scanner = new Scanner(System.in);

    while (scanner.hasNextInt()) {
      int val = scanner.nextInt();
      arr.add(val);
    }

    System.out.println(arr);

    int windowSize = 3;
    int sum = 0, maxSum = 0;

    for (int i = 0; i < windowSize; i++) {
      sum += arr.get(i);
    }

    System.out.println("initial sum -> " + sum);

    int j = windowSize;
    int i = 1;

    while (j < arr.size()) {
      sum -= arr.get(i - 1);
      sum += arr.get(j);
      System.out.println("next sum -> " + sum);
      if (sum > maxSum) {
        maxSum = sum;
      }
      i++;
      j++;
    }

    System.out.print("Max sum: " + maxSum);
  }
}
