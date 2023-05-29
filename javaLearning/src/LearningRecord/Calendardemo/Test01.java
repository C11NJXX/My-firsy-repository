package LearningRecord.Calendardemo;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Test01 {
    public static void main(String[] args) {
        Calendar calendar1 = new GregorianCalendar();//创建子类对象，用父类对象接收
        Calendar calendar = Calendar.getInstance();//调用静态方法从底层创建子类对象
        System.out.println(calendar);

        //通过get方法获取信息
        //3.获取属性
        int year = calendar.get(Calendar.YEAR);
        int month = calendar.get(Calendar.MONTH) + 1;//Calendar的月份值是0-11
        int day = calendar.get(Calendar.DAY_OF_MONTH);

        int hour = calendar.get(Calendar.HOUR);
        int minute = calendar.get(Calendar.MINUTE);
        int second = calendar.get(Calendar.SECOND);

        int week = calendar.get(Calendar.DAY_OF_WEEK);//返回值范围：1--7，分别表示："星期日","星期一","星期二",...,"星期六"
    }
}
