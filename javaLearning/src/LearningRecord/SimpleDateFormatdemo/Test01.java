package LearningRecord.SimpleDateFormatdemo;

/*
            public simpleDateFormat() 默认格式
            public simpleDateFormat(String pattern) 指定格式
            public final string format(Date date) 格式化(日期对象 ->字符串)
            public Date parse(string source) 解析(字符串 ->日期对象)
        */

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Test01 {
    static String pattern1 = "yyyy-MM-dd HH:mm:ss";
    static String pattern2 = "yyyy年MM月dd日 HH:mm:ss";
    public static void main(String[] args) throws ParseException {
        String str = "2023-05-27 17:05:59";
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        Date parse = simpleDateFormat.parse(str);
        System.out.println(parse);
        System.out.println(parse.getTime());

        method1();
        method2();
        method3();
    }
    public static void method1() {
        SimpleDateFormat simpleDateFormat1 = new SimpleDateFormat(pattern1);
        Date date = new Date(0L);
        System.out.println(simpleDateFormat1.format(date));
    } public static void method2() {
        SimpleDateFormat simpleDateFormat1 = new SimpleDateFormat();
        Date date = new Date(0L);
        System.out.println(simpleDateFormat1.format(date));
    }public static void method3() {
        SimpleDateFormat simpleDateFormat1 = new SimpleDateFormat(pattern2);
        Date date = new Date(0L);
        System.out.println(simpleDateFormat1.format(date));
    }
}
