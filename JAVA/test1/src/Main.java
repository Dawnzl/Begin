import java.util.Arrays;
import java.util.Scanner;
 
public class Main {
    public static int[] transform(int[] array) {
        int[] tmpArr = new int[array.length];

        for (int i = 0; i < array.length; i++) {
            tmpArr[i] = array[i] * 2;
        }
        return tmpArr;
    }

    public static void main(String[] args) {
        int[] array = {1, 2, 3};
        int[] ret = transform(array);
        System.out.println(Arrays.toString(array));
        System.out.println(Arrays.toString(ret));
    }
}