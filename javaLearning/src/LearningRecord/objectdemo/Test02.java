package LearningRecord.objectdemo;

import com.google.gson.Gson;

public class Test02 {
    public static void main(String[] args) throws CloneNotSupportedException {
        int[] arr = {1,2,3,4,5,6};
        Student s1 = new Student("a1",1,arr);
        //浅克隆
        //书写细节:
        //1.重写Object中的clone方法
        //2.让javabean类实现Cloneable接口
        //3.创建原对象并调用clone就可以了
        Student s2 = (Student)s1.clone();
        System.out.println(s2);
        //深克隆
        Student s3 = (Student)s2.clone();
        System.out.println(s3);
        //测试深克隆
        int[] arr1 = {1,2,3};
        s2.setArr(arr1);
        System.out.println(s2);
        System.out.println(s3);//没有跟随改变

        //利用第三方工具
        Gson gson = new Gson();
        //转变成字符串
        String s = gson.toJson(s1);
        System.out.println(s);
        //将字符串变回对象
        Student s4 = gson.fromJson(s, Student.class);
        System.out.println(s4);

     String s23 = "";
    }
}
