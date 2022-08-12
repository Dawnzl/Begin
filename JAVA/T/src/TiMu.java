import java.util.Scanner;


public class TiMu {
    /**
     * 求两个整数的最大值
     * @param a
     * @param b
     * @return
     */
    public static int max(int a,int b){
        return a > b ? a : b;
    }

    public static int max(int a,int b,int c){
        int ret = max(a,b);
        return ret > c ? ret : c;
    }

    public static void main(String[] args) {
        System.out.println(max(1, 2, 3));
    }

    public static void main13(String[] args) {
        int num = 0;
        int count = 0;
        for (num = 1; num <= 100; num++) {
            if (num % 10 == 9) {
                count++;
            }
            if (num / 10 == 9) {
                count++;
            }
        }
        System.out.println(count);
    }


    public static void main12(String[] args) {
        for(int year=1000;year<=2000;year++){
            boolean Isleapyear=false;
            if(year%4==0 && year % 100 !=0){
                Isleapyear=true;
            }
            if(year%400==0){
                Isleapyear=true;
            }
            if(Isleapyear){
                System.out.print(year+" ");
            }
        }
    }


    public static void main11(String[] args){
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int i=0;
        for(i=2;i<a;i++){
            if(a%i==0){
                break;
            }
        }
        if(i==a){
            System.out.println("是素数");
        }else{
            System.out.println("不是素数");
        }
        sc.close();
    }


    public static void main10(String[] args) {
        boolean flag = true;
        for (int i = 2; i < 100; i++) {
            for (int j = 2; j <= Math.sqrt(i); j++) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag){
                System.out.println(i);
            }
            flag = true;
        }
    }
    public static void main9(String[] args) {
        int n = 7;
        for (int i = 31; i >= 1 ; i-=2) {
            System.out.println( ( (n>>i) & 1)+ " ");
        }
        System.out.println();
        for (int i = 0; i >= 0; i-=2) {
            System.out.println(((n>>i)& 1)+" ");
        }
    }

    public static void main8(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = 3;
        while(count != 0){
            System.out.println("请输入密码（"+count+"次机会）：");
            String pass = scanner.nextLine();
            if(pass.equals("123")){
                System.out.println("登录成功！");
                break;
            }else{
                System.out.println("登录失败");
            }
            count--;
        }
    }

    public static void main7(String[] args) {
        int n = 123;
        while(n != 0){
            System.out.println(n%10);
            n = n /10;
        }
    }

    public static void main6(String[] args){
        for (int i = 1; i <= 9; i++){
            for (int j = 1; j <= i; j++){

                System.out.print(i + "*" + j + "=" + (i * j)+"\t");//   "\t"这是JAVA语言默认的制表符号,使用此符号，打印出的乘法表格较为美观
                if(i == j){
                    System.out.print("\n");//当换行条件成立时，进行换行打印
                }

            }
        }
    }


    public static void main5(String[] args) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9 ; j++) {
                System.out.print(i + "*" + j + "=" + i*j + " ");
            }
            System.out.println();
        }
    }



        public static void main4(String[] args)   {
            Scanner scan = new Scanner(System.in);
            while(scan.hasNextInt()){
                int n = scan.nextInt();
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if( (i==j) || (i+j==n-1) ){
                            System.out.print("*");
                        }else{
                            System.out.print(" ");
                        }
                    }
                    System.out.println();
                }
            }
        }



    public static void main3(String[] args) {
        for (int i = 1; i <= 999999; i++) {
            int count = 0;
            int tmp = i;
            int sum = 0;

            while(tmp != 0){
                tmp /= 10;
                count++;
            }
            //count里面是数字的位数
            tmp = i;
            while(tmp != 0){
                sum += Math.pow(tmp%10,count);
                tmp/=10;
            }
            if(sum == i){
                System.out.println(i);
            }
        }
    }

    public static void main2(String[] args) {

        int n = -1;
        int count = 0;
        for(int i = 0;i < 32;i++){
            if(((n >> i) & 1) != 0){
                count++;
            }
        }
            System.out.println(count);
        }

    public static void main1(String[] args) {
        double sum = 0.0;
        int flg = 1;
        for (int i = 1; i <= 100; i++) {
            sum = sum + 1.0/i * flg;
            flg = -flg;
        }
        System.out.println(sum);
    }
}
