package LearningRecord.Calendardemo;

import java.util.Calendar;

//计算班长出生那天是星期几(假如班长出生日期为：1998年3月18日)
public class Test02 {
    public static void main(String[] args) {
        Calendar calendar = Calendar.getInstance();
        calendar.set(Calendar.YEAR,1998);
        calendar.set(Calendar.MONTH,3-1);//注意一月是0
        calendar.set(Calendar.DAY_OF_MONTH,18);
        int week = calendar.get(Calendar.DAY_OF_WEEK)-1;
        System.out.println(week);
    }
}
