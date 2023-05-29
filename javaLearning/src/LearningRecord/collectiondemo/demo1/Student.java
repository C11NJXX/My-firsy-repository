package LearningRecord.collectiondemo.demo1;

import java.util.Objects;

public class Student {
    private int Id;
    private String name;

    public Student() {
    }

    public Student(int id, String name) {
        Id = id;
        this.name = name;
    }

    public int getId() {
        return Id;
    }

    public void setId(int id) {
        Id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;//在强转前，也要判断二者的类型是否一致，否则也会抛异常(这里相当直接return false了)
        Student student = (Student) o;//强制类型转化以便比较属性值
        return Id == student.Id && Objects.equals(name, student.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(Id, name);
    }
}
