import java.util.Random;
import java.util.Scanner;

public class J813 {

    public static int add(int a,int b) {
        return a+b;
    }
    public static void main(String[] args) {
        int x=1;
        int y = 2;
        int ret = add(x,y);
        System.out.println(ret);
    }


    //随机生成随机数
    public static void main3(String[] args) {
        Random random = new Random();
        int n = random.nextInt(100);
        System.out.println(n);
    }

    public static void main2(String[] args) {
        Scanner scan = new Scanner(System.in);

        //循环输入，处理单个数据
        while(scan.hasNextInt()){
            //hasNextInt与输入的情况有关
            System.out.println("输入你的年龄 ");
            int age = scan.nextInt();
            System.out.println("年龄："+age);
        }
        while(scan.hasNextLine()){
            String name = scan.nextLine();
        }

    }





    public static void main1(String[] args) {
        //有此定义才能从键盘输入，相当于创建一个键盘
        Scanner scan = new Scanner(System.in);

        //优先输入字符串，不然nextline会出错
        System.out.println("输入你的姓名");
        String name = scan.nextLine();
        System.out.println("姓名： "+name);

        System.out.println("输入你的年龄");
        int age = scan.nextInt();
        System.out.println("年龄： "+age);

        //关闭资源，相当于关闭键盘
        scan.close();
    }
}
