package LearningRecord.objectdemo;

import java.util.Arrays;
import java.util.Objects;

public class Student implements Cloneable {
    private String name;
    private int age;
    private int[] arr;
    public Student() {
    }

    public Student(String name, int age,int[] arr) {
        this.name = name;
        this.age = age;
        this.arr = arr;
    }

    /**
     * 获取
     * @return name
     */
    public String getName() {
        return name;
    }

    /**
     * 设置
     * @param name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * 获取
     * @return age
     */
    public int getAge() {
        return age;
    }

    /**
     * 设置
     * @param age
     */
    public void setAge(int age) {
        this.age = age;
    }

    public void setArr(int[] arr) {
        this.arr = arr;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", arr=" + Arrays.toString(arr) +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return age == student.age && Objects.equals(name, student.name);
    }

    //重写clone方法

    @Override
    protected Object clone() throws CloneNotSupportedException {
       //拷贝原数组
        int[] data = this.arr;
        //创建新数组
        int[]newData = new int[data.length];
        //拷贝
        for (int i = 0; i < data.length; i++) {
            newData[i] = data[i];
        }
        //先利用父类的clone方法，再替换需要深拷贝的地方
        Student u = (Student) super.clone();
        u.arr = newData;
        return u;
    }
}
