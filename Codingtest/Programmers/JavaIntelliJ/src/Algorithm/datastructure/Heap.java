package Algorithm.datastructure;

public class Heap {
    int SIZE;
    int MAX_SIZE = 1024;
    int[] arr;
//    static int[] arr = new int[SIZE];

    public void swap(int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
    public Heap() {
        this.SIZE = 0;
        this.arr = new int[MAX_SIZE];
    }

    public void insert(int data) {
        int here = ++SIZE;

        while ((here != 1) && (data < arr[here/2])){
            arr[here] = arr[here/2];
            here /= 2;
        }
        arr[here] = data;
    }

    public int deleteData() {
        if(SIZE == 0) return -1;
        int ret = arr[1];
        arr[1] = arr[SIZE--];
        int parent = 1;
        int child;

        while(true) {
            child = parent * 2;
            if( child + 1 <= SIZE && arr[child] > arr[child+1])
                child++;
            if(child > SIZE || arr[child] > arr[parent])
                break;
            swap(parent, child);
            parent = child;
        }

        return ret;
    }

    public static void main(String[] args) {
        Heap hp = new Heap();

        hp.insert(3);
        hp.insert(5);
        hp.insert(1);

        for (int i=1; i<=hp.SIZE; i++) {
            System.out.print(hp.arr[i] + " ");
        }
    }
}
