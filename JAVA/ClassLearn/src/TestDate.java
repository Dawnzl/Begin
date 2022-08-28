public class TestDate {
    public int year;
    public int month;
    public int day;

    public void setDate(TestDate this, int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }

    public void printDate(TestDate this) {
        System.out.println(this.year + "-" + this.month + "-" + this.day);
    }

    public static void main(String[] args) {
        TestDate testDate = new TestDate();

        testDate.setDate(2022, 8, 6);
        /*testDate.year = 2022;
        testDate.month = 8;
        testDate.day = 4;*/
        testDate.printDate();

    }
}


