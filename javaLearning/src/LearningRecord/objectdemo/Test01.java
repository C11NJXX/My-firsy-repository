package LearningRecord.objectdemo;

public class Test01 {
    public static void main(String[] args) {
        Student s1 = new Student("a1",1,null);
        Student s2 = new Student("a1",1,null);

        //默认继承object类中的equals方法，比较对象地址值，需要重写来比较对象的属性值
        boolean res = s1.equals(s2);
        System.out.println(res);
        //String 与StringBuilder
        String s = new String("abc");
        StringBuilder sb = new StringBuilder("abc");
        System.out.println(s.equals(sb));//s调用equals，在底层重写了方法
        System.out.println(sb.equals(s));//没有重写equals，使用object中的equals

    }
}
