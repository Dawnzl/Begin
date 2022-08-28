public class Student {

    public String name;
    public int age;

    public void setStudent(String name,int age){
        this.name = name;
        this.age = age;
    }

    public void print(){
        System.out.println(this.name+"=>"+this.age);
    }


    class Person{
        private String name;//私有的属性
        public int age;//公开的属性


        public void setName(String name){ //可用公开的方法改变私有的属性
            this.name=name;
        }

        public void show(){
            System.out.println("姓名："+name+" 年龄："+age);
        }
    }


    public static void main(String[] args) {
        /*Student student = new Student();
        student.setStudent("xiaozheng",20);
        student.print();*/


    }
}


