
class Dog{
    //属性-> 成员变量
    //字段
    public String name;
    public String color;

    //成员方法
    public void barks(){
        System.out.println(name + "汪汪叫！");
    }
    public void wag(){
        System.out.println(name + "摇尾巴！");
    }
}


public class Learn {
    public static void main(String[] args) {
        //实例化
        Dog dog1 = new Dog();
        dog1.name = "大黄";
        dog1.color = "黑色";
        dog1.barks();
        dog1.wag();
    }
}
