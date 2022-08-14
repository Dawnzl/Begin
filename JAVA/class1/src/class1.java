import java.util.Arrays;

public class class1 {
        public static void func1(int[] array) {
        int i = 0;
        int j = array.length - 1;
        while (i < j) {
            while (i < j && array[i] % 2 != 0) {
                i++;
            }
            while (i < j && array[j] % 2 == 0) {
                j--;
            }
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

        public static void main(String[] args){
        int[] array = {1, 2, 3, 4, 5, 6};
        func1(array);
        System.out.println(Arrays.toString(array));
    }
}

