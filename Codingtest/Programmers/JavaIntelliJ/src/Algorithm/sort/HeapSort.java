package Algorithm.sort;

public class HeapSort {
    public static void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    public static void heapify(int[] arr, int here, int size) {
        int left = here * 2 + 1;
        int right = here * 2 + 2;
        int max = here;
        if(left<size && arr[left]>arr[max])
            max = left;
        if(right<size && arr[right]>arr[max])
            max = right;
        if(max != here){
            heapify(arr, max, size);
        }
    }

    public static void buildHeap(int[] arr, int size) {
        for(int i=size/2-1; i>=0; i--) {
            heapify(arr, i, size);
            for(int j=0; j<size; j++) {
                System.out.print(arr[j]);
            }
            System.out.println();
        }
    }

    public static void heapSort(int[] arr, int size) {
        buildHeap(arr, size);
        for(int treeSize = size - 1; treeSize >= 0; treeSize--) {
            swap(arr, 0, treeSize);
            heapify(arr, 0, treeSize);
        }
    }

    public static void main(String[] args) {
        int[] arr = {9,8,1,2,3};
        int SIZE = arr.length;

        heapSort(arr, SIZE);

        for (int val:
                arr) {
            System.out.print(val + " ");
        }
    }

}
