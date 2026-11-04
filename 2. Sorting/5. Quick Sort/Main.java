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

    System.out.println(arr);

    QuickSort.quickSort(arr, 0, arr.size() - 1);

    System.out.println(arr);
  }
}

class QuickSort {
  public static void swap(List<Integer> arr, int i, int j) {
    int temp = arr.get(i);
    arr.set(i, arr.get(j));
    arr.set(j, temp);
  }

  public static void quickSort(List<Integer> arr, int left, int right) {
    if (left >= right) return;

    int i = left, j = right, pivot = left;

    while (i < j) {
      while (arr.get(pivot) >= arr.get(i) && i < right) {
        i++;
      }

      while (arr.get(pivot) < arr.get(j) && j > left) {
        j--;
      }

      if (i < j) {
        swap(arr, i, j);
      }
    }

    swap(arr, pivot, j);

    quickSort(arr, left, j - 1);

    quickSort(arr, j + 1, right);
  }
}
