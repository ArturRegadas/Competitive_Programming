import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n;
        long[] nums = new long[1000010];
        while(sc.hasNext()){
            n = sc.nextInt();
            for(int i =0;i<n;i++){
                nums[i] = sc.nextInt();
            }
            long Ra = 0, La = 0;
            int r=n-1, l=0;
            while(l<r){
                if(La+nums[l] <= Ra+nums[r]){
                    La+=nums[l];
                    l++;
                }
                else{
                    Ra+=nums[r];
                    r--;
                }
            }
            Ra += (Ra<La)? nums[r] : nums[r]*-1;
            System.out.println(Math.abs(La-Ra));
        }

        sc.close();
    }
}
