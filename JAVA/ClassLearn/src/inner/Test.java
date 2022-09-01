package inner;


class OuterClass{
    public int data1 = 1;
    int data2 = 2;
    public static int data3 = 3;

    public void test(){
        System.out.println("OuterClass::test()");
    }
    /**
     *   实例内部类
     *   1、如何获取 实例内部类的对象
     *               OuterClass.InnerClass innerClass =outerClass.new InnerClass();
     *   2、实例内部类中 不能有静态的成员变量 （先静态后构造），如果非要定义，那么只能被static final 修饰
     *   3、在实例内部类当中，如何访问外部类里相同的成员变量？
     *               在实例内部类当中 获取外部类的this：Out
     */

    class InnerClass{
        public int data4 = 4;
        int data5 = 5;
        //public static int data6; //实例内部类中 不能有静态的成员变量

        public void func(){
            System.out.println("InnerClass::func()");

            System.out.println(OuterClass.this.data1);//内部引用外部的类

            System.out.println(data1);
            System.out.println(data2);
            System.out.println(data3);
            System.out.println(data4);
            System.out.println(data5);

        }
    }


}

public class Test {
    public static void main(String[] args) {
        //外部类的引用对象
        OuterClass outerClass = new OuterClass();
        System.out.println(outerClass.data1);

        OuterClass.InnerClass innerClass =outerClass.new InnerClass();
    }
}
