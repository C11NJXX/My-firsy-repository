package LearningRecord.systemdemo;

public class Test02 {
    public static void main(String[] args) {
        int[] arr1 = {1,2,3,4,5,6,7,8,9,10};
        int[] arr2 = new int[10];
        System.arraycopy(arr1,0,arr2,0,10);
        for (int i = 0 ; i < 10 ; i++){
            System.out.println("i = " + i + '\n');
            System.out.println(arr2[i]);
        }
    }
}
