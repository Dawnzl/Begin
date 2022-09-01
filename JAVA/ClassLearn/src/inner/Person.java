package inner;

import com.sun.xml.internal.ws.api.model.wsdl.WSDLOutput;

class Person1{
    public int age = 18;
    public String name="bit";

    public void show(){
        System.out.println("姓名："+name+"年龄："+age);
    }

    @Override
    public String toString() {
        /*return "Person1{" +
                "age=" + age +
                ", name='" + name + '\'' +
                '}';*/
        return "姓名："+name+"年龄："+age;
    }

}

public class Person {
    public static void main(String[] args) {
        Person1 person1 = new Person1();
        System.out.println(person1);
    }



}
