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

    MergeSort.mergeSort(arr, 0, arr.size() - 1);

    System.out.println(arr);
  }
}

class MergeSort {
  public static void mergeSort(List<Integer> arr, int left, int right) {
    if (right <= left) return;

    int middle = Math.abs((right - left) / 2) + left;

    mergeSort(arr, left, middle);

    mergeSort(arr, middle + 1, right);

    int i = left, j = middle + 1;
    List<Integer> temp = new ArrayList<>();

    while (i <= middle && j <= right) {
      if (arr.get(i) < arr.get(j)) {
        temp.add(arr.get(i));
        i++;
      } else {
        temp.add(arr.get(j));
        j++;
      }
    }

    while (i <= middle) {
      temp.add(arr.get(i));
      i++;
    }

    while (j <= right) {
      temp.add(arr.get(j));
      j++;
    }

    for (int k = left; k <= right; k++) {
      arr.set(k, temp.get(k - left));
    }
  }
}
