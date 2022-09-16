package demo1;

import java.util.Arrays;
import java.util.Comparator;

class Student implements Comparable<Student>{ // 利用范型改造比较的方法
    public String name;
    public int age;
    // 构造
    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }
    // 重写字符串输出
    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
    // Comparable 重写比较方法 比较以年龄为准
    @Override
    public int compareTo(Student o) {
        if(this.age - o.age > 0) { // 以 调用该方法的age 与 引用的o的age作比较
            return 1;
        }else if(this.age - o.age < 0) {
            return -1;
        }else {
            return 0;
        }
        //return 0;
    }
}
// Comparator 比较器 ，类似提供一个比较模板，放在比较方法的后边
class AgeComparator implements Comparator<Student> {

    @Override
    public int compare(Student o1, Student o2) {
        return o1.age - o2.age;
    }
}

class NameComparator implements Comparator<Student> {

    @Override
    public int compare(Student o1, Student o2) {
        return o1.name.compareTo(o2.name);
    }
}

public class TEST {
    // 自定义的类想要比较，必须实现比较接口，所以冒泡传入的应该是已经完成接口化的Comparable[]数组类型
    public static void bubbleSort(Comparable[] array) {
        for (int i = 0; i < array.length-1; i++) {
            for (int j = 0; j < array.length-1-i; j++) {
                if(array[j].compareTo(array[j+1]) > 0) { // 不能直接大小进行比较，因为他是一个对象，要引用他本身的方法去调用
                    Comparable tmp = array[j];           // 创建存储类型也要是Comparable类型
                    array[j] = array[j+1];
                    array[j+1] = tmp;
                }
            }
        }
    }

    // 提供比较的算法
    public static void main(String[] args) {
        Student[] students = new Student[3];
        students[0] = new Student("ccc",10);
        students[1] = new Student("hello",40);
        students[2] = new Student("gbc",5);

        bubbleSort(students);

        System.out.println(Arrays.toString(students));

    }
    // 可以直接调用比较器中的方法进行比较，只需要引用比较双方的对象
    public static void main6(String[] args) {
        Student student1 = new Student("ccc",10);
        Student student2 = new Student("hello",40);

        AgeComparator ageComparator = new AgeComparator();

        if(ageComparator.compare(student1,student2) > 0) {
            System.out.println("student1 > student2");
        }else {
            System.out.println("student1 < student2");
        }
    }

    // new一个比较器对象，放入sort后边，可以达到自己的比较效果
    public static void main5(String[] args) {
        Student[] students = new Student[3];
        students[0] = new Student("ccc",10);
        students[1] = new Student("hello",40);
        students[2] = new Student("gbc",5);

        //AgeComparator ageComparator = new AgeComparator();
        NameComparator nameComparator = new NameComparator();
        Arrays.sort(students,nameComparator);

        System.out.println(Arrays.toString(students));
    }

    // student1 调用compareTo改写后的比较方法 并且引用 student2 （以年龄比较）
    public static void main4(String[] args) {
        Student student1 = new Student("ccc",10);
        Student student2 = new Student("hello",40);

        if(student1.compareTo(student2) > 0) {
            System.out.println("student1 > student2");
        }else {
            System.out.println("student1 < student2");
        }
    }

    // 基本的字符串比较方法
    public static void main2(String[] args) {
        String[] strings = {"abc","hello","bcd"};
        Arrays.sort(strings);
        System.out.println(Arrays.toString(strings));
    }

    // 原方法无法成功调用比较，会报错
    public static void main3(String[] args) {
        Student[] students = new Student[3];
        students[0] = new Student("ccc",10);
        students[1] = new Student("hello",40);
        students[2] = new Student("gbc",5);

        Arrays.sort(students);

        System.out.println(Arrays.toString(students));
    }

    // 正常数组比较
    public static void main1(String[] args) {
        int[] array = {1,4,2,7,3,8,5};
        Arrays.sort(array);
        System.out.println(Arrays.toString(array));
    }
}

