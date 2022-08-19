public class didi {
     public static int[] func2(int[] array,int target){
         int[] ret = new int[2];
         for (int i = 0;i < array.length;i++){
             for (int j = i+1;j < array.length;j++){
                 if (array[i] + array[j] == target){
                     ret[0] = i;
                     ret[1] = j;
                     return ret;
                 }
             }
         }
         return ret;
     }
     public static int func3(int[] array){
         int ret = array[0];
         for (int i = 1;i < array.length;i++){
             ret = ret ^ array[i];
         }
         return ret;
     }
}
