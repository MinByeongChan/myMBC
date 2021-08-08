package Algorithm.sort;

public class MergeSort {
    int[] arr;
    int SIZE = 0;


    MergeSort(int[] arr, int size) {
        this.arr = arr;
        this.SIZE = size;
    }
    public static void mergeSort(int[] arr, int left, int right) {
        if(left == right) return ;
        int mid = ( left + right ) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, right);
    }

    public static void merge(int[] arr, int left, int right) {
        int[] tmp = new int[arr.length];
        int mid = ( left + right ) / 2;
        int L = left, R = mid + 1;
        int k = left;

        while (L <= mid && R <= right) {
            tmp[k++] = arr[L] <= arr[R] ? arr[L++] : arr[R++];
        }

        if(L>mid)
            for(int i=R; i<=right; i++)
                tmp[k++] = arr[i];
        else
            for(int i=L; i<=mid; i++)
                tmp[k++] = arr[i];

        for(int i=left; i<=right; i++)
            arr[i] = tmp[i];
    }

    public static void main(String[] args) {
        int[] arr = {8,1};
        int SIZE = arr.length;

        MergeSort mg = new MergeSort(arr, SIZE);
        mg.mergeSort(arr, 0, SIZE-1);

        for (int val:
                mg.arr) {
            System.out.print(val + " ");
        }

    }
}
