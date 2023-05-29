package LearningRecord.datedemo;

import java.util.Date;

public class Test02 {
    public static void main(String[] args) {
        Date date1 = new Date();
        System.out.println(date1.getTime());
        long time = System.currentTimeMillis();
        Date date2 = new Date();
        date2.setTime(time);
        System.out.println(date2);
    }
}
