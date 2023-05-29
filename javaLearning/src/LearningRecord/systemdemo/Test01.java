package LearningRecord.systemdemo;

public class Test01 {
    public static void main(String[] args) {
        //利用时间差计算程序执行时间
        long begin = System.currentTimeMillis();
        for (int i = 0; i < 99999; i++) {
            if(isPrime(i)) {
                System.out.println(i + "");
            }
        }
        long end = System.currentTimeMillis();
        System.out.println(end-begin);
    }
    public static boolean isPrime(int num) {
        //判断是否为质数，并优化循环次数
        //int count = 0;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            //count++;
            if(num % i == 0){
                //System.out.println(count);
                return false;
            }
        }
        //System.out.println(count);
        return true;
    }
}
