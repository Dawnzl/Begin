package book;

public class BookList {

    public Book[] books = new Book[10];
    public int usedSize; // 存储当前书的个数

    /**
     * 事先通过构造方法 初始化的时候 给数组里面预存三本书，usedSize = 3
     */
    public BookList(){
        books[0] = new Book("三国演义","罗贯中",89,"小说");
        books[1] = new Book("西游记","吴承恩",79,"小说");
        books[2] = new Book("红楼梦","曹雪芹",52,"小说");
        this.usedSize = 3;
    }






}


