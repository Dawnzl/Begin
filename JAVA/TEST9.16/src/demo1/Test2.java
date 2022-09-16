package demo1;

class Money implements Cloneable{
    public double m = 12.5;
    // 调用父类的clone接口
    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }

}

class Person implements Cloneable{
    public int id;
    public Money money = new Money();
    // 重写克隆方法（深拷贝）
    @Override
    protected Object clone() throws CloneNotSupportedException {
        //return super.clone();
        Person tmp = (Person) super.clone(); // 调用父类的克隆方法先浅拷贝一个副本
        tmp.money = (Money) this.money.clone();// 将副本里的元素money类也进行拷贝处理（因为money类中已经调用了父类的拷贝方法）
        return tmp;
    }

    @Override
    public String toString() {
        return "Person{" +
                "id=" + id +
                '}';
    }
}
public class Test2 {
    public static void main(String[] args) throws CloneNotSupportedException{
        Person person = new Person();

        Person person2 = (Person)person.clone();
        person2.money.m = 1999;

        System.out.println("person："+person.money.m);

        System.out.println("person2："+person2.money.m);
    }
}