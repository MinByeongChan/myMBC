package Algorithm.sort;

public class MergeSort {

    public static void mergeSort(int[] arr, int left, int right) {
        if(left==right) return;
        int mid;

        mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, right);
    }

    public static void merge(int[] arr, int left, int right) {
        int L, R, k, a;
        int mid = ( left+right ) / 2;
        L = left;
        R = mid + 1;
        k = left;
        int[] tmp = new int[arr.length];

        while (L <= mid && R <= right)
            tmp[k++] = arr[L] <= arr[R] ? arr[L++] : arr[R++];

        if(L > mid)
            for(a = R; a<=right; a++)
                tmp[k++] = arr[a];
        else
            for(a = L; a<=mid; a++)
                tmp[k++] = arr[a];
        for( a=left; a<=right; a++)
            arr[a] = tmp[a];
    }

    public static void main(String[] args) {
        int[] arr = {9,8,1,2,3};
        int SIZE = arr.length;

        mergeSort(arr, 0, SIZE-1);

        for (int val:
                arr) {
            System.out.print(val + " ");
        }

    }
}
