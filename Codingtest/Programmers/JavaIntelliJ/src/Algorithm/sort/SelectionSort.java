package Algorithm.sort;

import java.util.Collections;

public class SelectionSort {

    public static void main(String[] args) {
        int[] arr = {9,8,1,2,3};
        int minIndex;
        for(int i=0; i<arr.length; i++) {
            minIndex = i;

            for(int j=i+1; j<arr.length; j++) {
                if(arr[minIndex] > arr[j])
                    minIndex = j;
            }

            int tmp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = tmp;
        }
        for (int val:
             arr) {
            System.out.print(val+" ");
        }
    }
}
