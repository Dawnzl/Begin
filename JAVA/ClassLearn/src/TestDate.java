public class TestDate {
    public int year;
    public int month;
    public int day;

    public void setDate(int y,int m,int d){
        year = y;
        month = m;
        day = d;
    }

    public void printDate(){
        System.out.println(year+"-"+month+"-"+day);
    }

    public static void main(String[] args) {
        TestDate testDate = new TestDate();
        testDate.year = 2022;
        testDate.month = 8;
        testDate.day = 4;

        testDate.printDate();

    }

}
