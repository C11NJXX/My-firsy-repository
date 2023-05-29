package LearningRecord.collectiondemo.demo1;

import java.util.ArrayList;
import java.util.Collection;

//| boolean contains(Object o) | 判断集合中是否存在指定的元素       |
//当存储的是自定义类型时，要重写equals函数再调用contains（底层调用equals）
public class Test02 {
    public static void main(String[] args) {
        Collection<Student> studentCollection = new ArrayList<>();
        studentCollection.add(new Student(3,"C"));
        Student student = new Student(3,"C");
        boolean isContains = studentCollection.contains(student);
        System.out.println(isContains);
        System.out.println(student.equals(new String("abc")));

    }
}
