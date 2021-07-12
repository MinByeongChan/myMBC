package Algorithm.sort;

public class InsertionSort {

    public static void main(String[] args) {
        int[] arr = {9,8,1,2,3};
        int SIZE = arr.length;
        int i, j, key;

        for(i=1; i<SIZE; i++) {
            key = arr[i];
            j = i - 1;
            while(j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }

        for (int val:
             arr) {
            System.out.print(val+" ");
        }
    }
}
