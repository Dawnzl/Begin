package demo;

interface IFlying{
    void flying();
}
interface ISwimming{
    void swimming();
}
interface IRunning{
    void running();
}

class Animal{
    public String name;
    public int age;
    // 构造方法
    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }
    // 实例方法
    public void eat(){
        System.out.println("吃饭");
    }
}

class Dog extends Animal implements IRunning,ISwimming{
    // 父类的继承（生物共性用继承）
    public Dog(String name, int age) {
        super(name, age);
    }
    // 重写行为（行为动作共性用接口）
    @Override
    public void swimming() {
        System.out.println(name + "正在游泳");
    }
    @Override
    public void running() {
        System.out.println(name + "正在跑");
    }

    // 甚至可以重写父类的行为（动态绑定）
    @Override
    public void eat() {
        System.out.println(name+"正在吃狗粮");
    }
}

class Bird extends Animal implements IFlying{

    public Bird(String name, int age) {
        super(name, age);
    }
    @Override
    public void flying() {
        System.out.println(name + "正在飞！");
    }
}

class Duck extends Animal implements IFlying,ISwimming,IRunning{

    public Duck(String name, int age) {
        super(name, age);
    }

    @Override
    public void flying() {
        System.out.println(name + "正在飞！");

    }
    @Override
    public void swimming() {
        System.out.println(name + "正在游泳");
    }
    @Override
    public void running() {
        System.out.println(name + "正在跑");
    }
}
class Robot implements IRunning{
    @Override
    public void running() {
        System.out.println("机器人正在跑");
    }
}
public class Test3 {
        public static void walk(IRunning iRunning){
            iRunning.running();
        }
        // 实现多态
        public static void func(Animal animal){
            animal.eat();
        }

    public static void main(String[] args) {
        walk(new Dog("Huang",10) );
        walk(new Duck("Ming",10) );
        // 接口构造行为甚至可以————只要具备这个行为的东西就可以触发，不用继承
        walk(new Robot());
        System.out.println("======================");
        func(new Dog("Huang",10));
        func(new Duck("Ming",10));
    }
}


