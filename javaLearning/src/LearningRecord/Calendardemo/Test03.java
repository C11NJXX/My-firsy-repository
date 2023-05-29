package LearningRecord.Calendardemo;

import java.util.Calendar;

//计算200天以后是哪年哪月哪日，星期几？
public class Test03 {
    public static void main(String[] args) {
        Calendar calendar = Calendar.getInstance();
        calendar.add(Calendar.DAY_OF_YEAR,200);
        int year = calendar.get(Calendar.YEAR);
        int mouth = calendar.get(Calendar.MONTH)+1;
        int day = calendar.get(Calendar.DAY_OF_MONTH);
        int wk = calendar.get(Calendar.DAY_OF_WEEK)-1;
        System.out.println("200天后是：" + year + "年" + mouth + "月" + day + "日" + getWeek(wk));

    }
    //查表法，查询星期几
    public static String getWeek(int w) {//w = 1 --- 7
        //做一个表(数组)
        String[] weekArray = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
        //            索引      [0]      [1]       [2]      [3]       [4]      [5]      [6]
        //查表
        return weekArray[w - 1];
    }
}
