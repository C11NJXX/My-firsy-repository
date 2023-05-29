package LearningRecord.SimpleDateFormatdemo;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/* 需求:
            秒杀活动开始时间:2023年11月11日 0:0:0(毫秒值)
            秒杀活动结束时间:2023年11月11日 0:10:0(毫秒值)

            小贾下单并付款的时间为:2023年11月11日 0:01:0
            小皮下单并付款的时间为:2023年11月11日 0:11:0
            用代码说明这两位同学有没有参加上秒杀活动?
         */
public class Test02 {
    static String pattern = "yyyy-MM-dd HH:mm:ss";
    public static void main(String[] args) throws ParseException {
        String start = "2023-11-11 0:0:0";
        String order = "2023-11-11 0:09:61";//不会报错
        String end = "2023-11-11 0:10:0";
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat(pattern);
        Date parse1 = simpleDateFormat.parse(start);
        Date parse2 = simpleDateFormat.parse(end);
        Date parse3 = simpleDateFormat.parse(order);
        if(parse3.getTime() >= parse1.getTime() && parse3.getTime() <= parse2.getTime()) {
            System.out.println("T");
        }else{
            System.out.println("F");
        }

    }
}
