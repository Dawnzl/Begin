package demo;

interface IShape{
    void draw();
}
class Rect implements IShape{

    @Override
    public void draw() {
        System.out.println("矩形！");
    }
}
class Flower implements IShape{

    @Override
    public void draw() {
        System.out.println("花朵！");
    }
}
public class Test {
    public static void drawMap(IShape iShape){
        iShape.draw();
    }
    public static void main(String[] args) {
        Rect rect = new Rect();
        drawMap(rect);
        drawMap(new Flower());// 向上转型动态绑定也可以
        //IShape iShape= new Rect(); // 看成特殊的一种类
    }
}

