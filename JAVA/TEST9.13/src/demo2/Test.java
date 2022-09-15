package demo2;

abstract class Shape{
    // 抽象方法，在父类不用具体实现，在子类重写
    public abstract void draw();//有抽象方法就必须是抽象类

}
abstract class A extends Shape{
    // 没有对父类Shape的抽象方法进行重写，但是也不会出错
}

public class Test {



}
