package LearningRecord.datedemo;

import java.util.Date;

public class Test01 {
    public static void main(String[] args) {
        Date date = new Date();
        Date date1 = new Date(0L);
        System.out.println(date);
        //指定时间,0L代表从时间原点过了0ms
        System.out.println(date1);
    }
}
