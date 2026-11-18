// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

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

    int i = 0, j = 0;
    List<Integer> union = new ArrayList<>();

    while (i < arr1.size() && j < arr2.size()) {
      Integer lastElement = union.size() == 0 ? null : union.get(union.size() - 1);

      if (arr1.get(i) != lastElement && arr1.get(i) <= arr2.get(j)) {
        union.add(arr1.get(i));
        i++;
      } else if (arr2.get(j) != lastElement && arr2.get(j) < arr1.get(i)) {
        union.add(arr2.get(j));
        j++;
      } else if (arr1.get(i) == lastElement) {
        i++;
      } else if (arr2.get(j) == lastElement) {
        j++;
      }
    }

    while (i < arr1.size()) {
      Integer lastElement = union.size() == 0 ? null : union.get(union.size() - 1);

      if (arr1.get(i) != lastElement) union.add(arr1.get(i));

      i++;
    }

    while (j < arr2.size()) {
      Integer lastElement = union.size() == 0 ? null : union.get(union.size() - 1);

      if (arr2.get(j) != lastElement) union.add(arr2.get(j));

      j++;
    }

    System.out.println("Array 1: " + arr1);
    System.out.println("Array 2: " + arr2);
    System.out.println("Union: " + union);
  }
}
