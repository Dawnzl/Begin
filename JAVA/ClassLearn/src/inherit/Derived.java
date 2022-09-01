package inherit;

class Base{
    int a;
    int b;
}
public class Derived extends Base {
    int c;

    public void method() {
        a = 10;
        b = 20;
        c = 30;
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);

    }


    public static void main(String[] args) {
        Derived derived =new Derived();
        derived.method();
    }
}
