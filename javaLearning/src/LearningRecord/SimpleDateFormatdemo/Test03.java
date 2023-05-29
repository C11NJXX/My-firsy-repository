package LearningRecord.SimpleDateFormatdemo;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/*
     假设，你初恋的出生年月日为:2000-11-11
     请用字符串表示这个数据，并将其转换为:2000y11m11d

     创建一个Date对象表示2000y11m11d
     创建一个SimpleDateFormat对象，并定义格式为年月日把时间变成:2000y11m11d
*/
public class Test03 {
    static String patter1 = "yyyy'y'MM'm'dd";
    static String patter2 = "yyyy-MM-dd";
    public static void main(String[] args) throws ParseException {
        SimpleDateFormat simpleDateFormat1 = new SimpleDateFormat(patter1);
        SimpleDateFormat simpleDateFormat2 = new SimpleDateFormat(patter2);
        String birth = "2000-11-11";
        Date birth1 = simpleDateFormat2.parse(birth);
        String birth2 = simpleDateFormat1.format(birth1);
        System.out.println(birth2);
    }
}
