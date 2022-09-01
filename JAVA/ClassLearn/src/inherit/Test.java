package inherit;


class Dog{
    public String name;
    public int age;

    public void barks(){
        System.out.println(name+"汪汪叫！");
    }
    public void eat(){
        System.out.println(name+"eating！");
    }
}

class Cat{
    public String name;
    public int age;

    public void eat(){
        System.out.println(name+"eating！");
    }
    public void catchMouse(){
        System.out.println(name+"正在抓老鼠");
    }
}

public class Test {
    public static void main(String[] args) {

    }
}
