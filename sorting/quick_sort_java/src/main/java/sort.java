import java.util.Random;

public class sort {

    public static void main(String[] args) {
        int maxElements = 500000;

        int[] arr = fillArray(maxElements);

        print(arr);

        long start = System.currentTimeMillis();
        quicksort(arr, 0, maxElements - 1);
        long end = System.currentTimeMillis();

        print(arr);
        long timeElapsed = end - start;
        System.out.println("Time elapsed: " + timeElapsed + "ms");
    }

    public static int[] fillArray(int maxElements) {
        int[] list = new int[maxElements];
        Random rnd = new Random();

        for(int i = 0; i < maxElements; i++) {
            list[i] = rnd.nextInt(50) + 1;
        }

        return list;
    }

    public static void print(int[] arr) {
        for(int i : arr) {
            System.out.print(i + " ");
        }

        System.out.println(" ");
    }

    public static void quicksort(int[] arr, int start, int end) {
        if((end - start) < 1) {
            return;
        }

        int pivot = start;
        int i = start;
        int k = end;
        int tmp;

        while (i < k) {

            while(arr[i] <= arr[pivot] && i < end) i++;
            while(arr[k] > arr[pivot]) k--;

            if(i < k) {
                tmp = arr[i];
                arr[i] = arr[k];
                arr[k] = tmp;
            }

        }

        tmp = arr[pivot];
        arr[pivot] = arr[k];
        arr[k] = tmp;

        quicksort(arr, start, k - 1);
        quicksort(arr, k + 1, end);
    }

}
