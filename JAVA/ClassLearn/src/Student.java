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




    public static void main(String[] args) {
        Student student = new Student();
        student.setStudent("xiaozheng",20);
        student.print();
    }
}


