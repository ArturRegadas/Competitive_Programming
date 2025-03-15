import java.util.*;

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int n = sc.nextInt();
            boolean[] dp = new boolean[150001];
            int[] nums = new int[155];
            dp[0] = true;
            int sum = 0;
            for(int i =0;i<n;i++){
                 nums[i]= sc.nextInt();
                 sum+=nums[i];
            }
            int mid = sum/2;
            for(int i =0;i<n;i++){
                for(int j = mid; j>=nums[i]; j--)
                    dp[j] |= dp[j-nums[i]];
            }
            for(int i = mid; i>=0;i--){
                if(dp[i]){
                    System.out.printf("%d\n",sum - 2*i);
                    break;
                }
            }
        }
        

        sc.close();
    }
}