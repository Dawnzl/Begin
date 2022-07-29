/**
 * 7.27
 */

public class test {
    public static void main(String[] args) {
        double sum = 0.0;
        int flg = 1;
        for (int i = 0; i <= 100; i++) {
            sum = sum + 1.0/i * flg;
            flg = -flg;
        }
        System.out.println(sum);
    }
    public static void main3(String[] args) {
        int n = -1;
        int count = 0;
        for(int i = 0;i < 32;i++){
            if(((n >> i) & 1) != 0){
                count++;
            }
        }
        System.out.println(count);
    }
    public static void main2(String[] args) {
        //逻辑控制

    }
    public static void main1(String[] args) {
        System.out.println("hello");
        short a =128;
        byte b =(byte) a;
        System.out.println(a);
        System.out.println(b);
/*所以对于short类型的128的原码是：
0000 0000 1000 0000；
强制转换为byte后，只剩下后面的8位了，即：
1000 0000；这个作为了byte的补码；
所以是-128；*/

        System.out.println(5/2);
        System.out.println(5.0/2);
        System.out.println(5/2.0);
        System.out.println((float) 5/2);
        System.out.println(5/(float)2);
        System.out.println((float)(5/2));

        System.out.println(10%3);//1
        System.out.println(-10%3);//-1
        System.out.println(10%-3);//1
        System.out.println(-10%-3);//-1
        //java可以小数取余
        System.out.println(-12.5%-10.5);//-2.0


        //bool表达式里左右两式都要是bool类型（ture或者false），没有真为1，假为0这种说法
        //!后一定要一个布尔表达式



    }
}



