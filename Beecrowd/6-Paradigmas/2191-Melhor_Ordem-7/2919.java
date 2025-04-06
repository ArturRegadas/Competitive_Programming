import java.util.*;

public class Main {
    public static int lowerBound(ArrayList<Integer> arr, int target) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr.get(mid) < target) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    public static int LIS(int[] nums) {
        ArrayList<Integer> lis = new ArrayList<>();
        for (int num : nums) {
            int idx = lowerBound(lis, num);
            if (idx == lis.size()) lis.add(num);
            else lis.set(idx, num);
        }
        return lis.size();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
            System.out.println(LIS(nums));
        }
    }
}
