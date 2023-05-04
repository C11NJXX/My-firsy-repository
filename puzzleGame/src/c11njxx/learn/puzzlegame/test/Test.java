package c11njxx.learn.puzzlegame.test;

import java.util.*;

//创建一维数组打乱后放到二维数组
public class Test {
    public static void main(String[] args) {
        //创建一维数组
        int[] tempArr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        //打乱一维数组
        Random r = new Random();
        for (int i = 0; i < tempArr.length; i++) {
            //获取随机索引
            int index = r.nextInt(tempArr.length);
            //交换随机索引与循环索引
            int temp = tempArr[i];
            tempArr[i] = tempArr[index];
            tempArr[index] = temp;
        }
        //测试遍历
        for (int i1 = 0; i1 < tempArr.length; i1++) {
            System.out.print(tempArr[i1] + " ");
        }
        System.out.println();
        //创建二维数组
        int[][] data  = new int[4][4];
        //添加数据
        for (int i = 0; i < tempArr.length; i++) {
            data[i/4][i%4] = tempArr[i];
        }
    }

}
