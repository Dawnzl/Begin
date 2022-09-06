
class Person{
    private String name;//私有的属性
    public int age;//公开的属性


    public void setName(String name){ //可用公开的方法改变私有的属性
        this.name=name;
    }
    public String getName(){
        return this.name;
    }
    public void show(){
        System.out.println("姓名："+name+" 年龄："+age);
    }
}

public class FZ {
    public static void main(String[] args) {
        Person person = new Person();
        //person.name = "xiao";会报错，因为他是私有的属性无法调用
        person.setName("bit");
        System.out.println(person.getName());

    }
}
