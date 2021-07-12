package Algorithm.sort;

public class BubbleSort {

    public static void main(String[] args) {
        int[] arr = {9,8,1,2,3};
        int SIZE = arr.length;
        for(int i = SIZE-1; i > 0; i--) {
            for(int j=0; j<i; j++) {
                if(arr[j] > arr[j+1]){
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
        }

        for (int val:
             arr) {
            System.out.print(val + " ");
        }
    }
}
