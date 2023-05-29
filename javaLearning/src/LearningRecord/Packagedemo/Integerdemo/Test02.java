package LearningRecord.Packagedemo.Integerdemo;
//自动装箱拆箱
public class Test02 {
    public static void main(String[] args) {
        //装箱
        Integer i = new Integer(10);//10->i
        Integer i1 = Integer.valueOf(10);
        //拆箱
        System.out.println(i1.intValue());
        //自动装/拆箱
        Integer i2 = 10;//省略了
        i2 = i2 + 3;//i2先自动拆箱变成10 ，与3相加后自动装箱 13 -> i2
    }
}
