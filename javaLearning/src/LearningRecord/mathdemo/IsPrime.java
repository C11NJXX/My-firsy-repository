package LearningRecord.mathdemo;

public class IsPrime {
    public static void main(String[] args) {
        System.out.println(isPrime(999));
    }
    public static boolean isPrime(int num) {
        //判断是否为质数，并优化循环次数
        int count = 0;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            count++;
            if(num % i == 0){
                System.out.println(count);
                return false;
            }
        }
        System.out.println(count);
        return true;
    }
}
