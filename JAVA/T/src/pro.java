import java.util.Scanner;

public class pro {

        public static void main(String[] args) {
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9 ; j++) {
                    System.out.println(i+"*"+j+"="+i*j + "\t");
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

