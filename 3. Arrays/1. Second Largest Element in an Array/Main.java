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

    System.out.println(getSecondLargestElement(arr));
  }

  public static Integer getSecondLargestElement(List<Integer> arr) {
    if (arr.size() <= 1) return null;

    int largestElement = arr.get(0);
    Integer secondLargestElement = null;

    for (int i = 1; i < arr.size(); i++) {
      if (arr.get(i) < largestElement
          && (secondLargestElement != null && arr.get(i) > secondLargestElement
              || secondLargestElement == null)) {
        secondLargestElement = arr.get(i);
      } else if (arr.get(i) > largestElement) {
        secondLargestElement = largestElement;
        largestElement = arr.get(i);
      }
    }

    return secondLargestElement;
  }
}
