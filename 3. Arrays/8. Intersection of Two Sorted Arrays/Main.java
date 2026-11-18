// https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-array-1587115620/1

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main {
  public static void main(String args[]) {
    Scanner lineScanner = new Scanner(System.in);

    String line1 = lineScanner.nextLine();
    String line2 = lineScanner.nextLine();

    lineScanner.close();

    Scanner scanner1 = new Scanner(line1);
    Scanner scanner2 = new Scanner(line2);

    List<Integer> arr1 = new ArrayList<>();
    List<Integer> arr2 = new ArrayList<>();

    while (scanner1.hasNextInt()) arr1.add(scanner1.nextInt());

    while (scanner2.hasNextInt()) arr2.add(scanner2.nextInt());

    scanner1.close();
    scanner2.close();

    System.out.println("Array 1: " + arr1);
    System.out.println("Array 2: " + arr2);
    System.out.println(
        "Intersection: "
            + Solution.intersection(
                arr1.stream().mapToInt(Integer::intValue).toArray(),
                arr2.stream().mapToInt(Integer::intValue).toArray()));
  }
}

class Solution {
  static ArrayList<Integer> intersection(int arr1[], int arr2[]) {
    ArrayList<Integer> result = new ArrayList<>();

    int i = 0, j = 0;

    while (i < arr1.length && j < arr2.length) {
      int lastElement = result.size() == 0 ? -1 : result.get(result.size() - 1);

      if (arr1[i] == arr2[j] && arr1[i] != lastElement) {
        result.add(arr1[i]);
        i++;
        j++;
      } else if (arr1[i] <= arr2[j]) {
        i++;
      } else if (arr2[j] < arr1[i]) {
        j++;
      }
    }

    return result;
  }
}
