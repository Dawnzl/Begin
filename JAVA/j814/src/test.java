
class test {


    public static int func3(int[] array){
        int ret = array[0];
        for (int i = 1 ; i < array.length; i++) {
            ret = ret ^ array[i];
        }
        return ret;
    }

    public static void main(String[] args) {
        int[] array = {4,1,2,1,2};
        System.out.println(func3(array));

    }
}
