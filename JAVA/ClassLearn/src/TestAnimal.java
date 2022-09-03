class Animal{
    public String name;
    public int age;

    public void eat(){
        System.out.println(name+"吃饭");
    }
}

class Dog1 extends Animal{
    // 傻 是狗1的特殊属性
    public String silly;
    public void houseGuard(){
        System.out.println(super.name+"正在看家护院");
        System.out.println(name+"正在看见护院");
    }
}

class Cat extends Animal{
    // 猫特有的行为
    public void catchMouse(){
        System.out.println(name+"抓老鼠");
    }
}

public class TestAnimal {
    public static void main(String[] args) {
        Dog1 dog = new Dog1();
        Cat cat = new Cat();

    }
}
