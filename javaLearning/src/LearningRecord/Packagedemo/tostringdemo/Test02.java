package LearningRecord.Packagedemo.tostringdemo;
/*除了Character类之外，其他所有包装类都具有parseXxx静态方法可以将字符串参数转换为对应的基本类型*/
public class Test02 {
    public static void main(String[] args) {
        String s = "100";
        /*- `public static byte parseByte(String s)`：将字符串参数转换为对应的byte基本类型。
- `public static short parseShort(String s)`：将字符串参数转换为对应的short基本类型。
- **`public static int parseInt(String s)`：将字符串参数转换为对应的int基本类型。**
- **`public static long parseLong(String s)`：将字符串参数转换为对应的long基本类型。**
- `public static float parseFloat(String s)`：将字符串参数转换为对应的float基本类型。
- `public static double parseDouble(String s)`：将字符串参数转换为对应的double基本类型。
- `public static boolean parseBoolean(String s)`：将字符串参数转换为对应的boolean基本类型。*/
        byte b = Byte.parseByte(s);
        System.out.println(b);

        //将字符串转变成integer
        //way1
        String s1 = "3";
        //先创建integer
        Integer integer = Integer.valueOf(s1);
        System.out.println(integer.intValue());
        //way2
        //直接调用静态方法转
        int i = Integer.parseInt(s1);
        System.out.println(i);
    }
}
