class Animal{
    public String name;
    public int age;

    public Animal(String name,int age)//父类构造方法
    {
        this.name = name;
        this.age = age;
    }

    public void eat(){
        System.out.println(name+"吃饭");
    }
}

class Dog1 extends Animal{
    // 傻 是狗1的特殊属性
    public boolean silly;

    //有参数要自己显性构造方法
    public Dog1(String name,int age,boolean silly){
        super(name,age);//必须在第一行,先帮父类部分初始化
        this.silly = silly;
    }
    public void houseGuard(){
        System.out.println(super.name+"正在看家护院");
        System.out.println(name+"正在看见护院");
    }
}

/*class Cat extends Animal{
    // 猫特有的行为
    public void catchMouse(){
        System.out.println(name+"抓老鼠");
    }
}*/

public class TestAnimal {
    public static void main(String[] args) {
        Dog1 dog = new Dog1("xiao",18,false);
        //Cat cat = new Cat();

    }
}

