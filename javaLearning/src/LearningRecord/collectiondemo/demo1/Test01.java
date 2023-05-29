package LearningRecord.collectiondemo.demo1;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

public class Test01 {
    public static void main(String[] args) {
        Collection<String> collection = new ArrayList<>();
        collection.add("a");
        collection.add("b");
        collection.add("c");
        collection.add("d");
        collection.add("e");
        collection.add("f");//此时不会报错
        //创建迭代器
        Iterator<String> iterator = collection.iterator();
        //利用循环遍历
        while(iterator.hasNext()) {
            String str = iterator.next();
            String next = iterator.next();//如果在循环中写两个next函数，那么在集合元素为奇数时，最后一次调用next会超出范围
            System.out.println(str);
            System.out.println(next);
        }
    }
}

/*- Collection集合概述

  - 是单例集合的顶层接口,它表示一组对象,这些对象也称为Collection的元素
  - JDK 不提供此接口的任何直接实现.它提供更具体的子接口(如Set和List)实现

- 创建Collection集合的对象

  - 多态的方式
  - 具体的实现类ArrayList

- Collection集合常用方法

  | 方法名                     | 说明                               |
  | :------------------------- | :--------------------------------- |
  | boolean add(E e)           | 添加元素                           |
  | boolean remove(Object o)   | 从集合中移除指定的元素             |
  | boolean removeIf(Object o) | 根据条件进行移除                   |
  | void   clear()             | 清空集合中的元素                   |
  | boolean contains(Object o) | 判断集合中是否存在指定的元素       |
  | boolean isEmpty()          | 判断集合是否为空                   |
  | int   size()               | 集合的长度，也就是集合中元素的个数 |
  */