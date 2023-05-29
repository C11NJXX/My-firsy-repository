package LearningRecord.Packagedemo.tostringdemo;
/*### 基本类型转换为String

- 转换方式
- 方式一：直接在数字后加一个空字符串
- 方式二：通过String类静态方法valueOf()
* */
public class Test01 {
    public static void main(String[] args) {
        int num = 10;
        String s1 = num + "";
        System.out.println(s1);

        String s2 = String.valueOf(10);
        System.out.println(s2);

    }
}
