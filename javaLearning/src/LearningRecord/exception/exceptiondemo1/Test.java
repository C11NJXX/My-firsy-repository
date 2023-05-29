package LearningRecord.exception.exceptiondemo1;

import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        //创建对象，并录入数据
        Scanner scanner = new Scanner(System.in);
        GirlFriend girlFriend = new GirlFriend();
        while (true) {
            try {
                //录入姓名(length 3-18)
                System.out.println("Input name ->");
                girlFriend.setName(scanner.nextLine());
                //录入年龄，可以接受任何字符(18-20)
                System.out.println("Input age ->");
                String strName = scanner.nextLine();
                //数据类型转换
                int age = Integer.parseInt(strName);
                girlFriend.setAge(age);
                //没有抛出异常
                break;
            } catch (NumberFormatException e) {
                System.out.println("年龄格式有误请重新输入");
                e.printStackTrace();
                continue;
            }catch (RuntimeException e) {
                System.out.println("姓名的长度或年龄范围有误");
                e.printStackTrace();
                continue;
            }
        }

        System.out.println(girlFriend);


    }
}
