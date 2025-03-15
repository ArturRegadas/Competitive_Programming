using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public static void Main() {
        while (true) {
            try {
                int n = int.Parse(Console.ReadLine());
                List<int> nums = Console.ReadLine().Trim().Split(' ').Select(int.Parse).ToList();

                int total = nums.Sum();
                int midle = total / 2;

                bool[] dp = new bool[midle + 1];
                dp[0] = true;

                foreach (int i in nums) {
                    for (int j = midle; j >= i; j--) {
                        dp[j] |= dp[j - i];
                    }
                }

                for (int i = midle; i >= 0; i--) {
                    if (dp[i]) {
                        Console.WriteLine(total - 2 * i);
                        break;
                    }
                }
            } 
            catch (Exception e) {
                break;
            }
        }
    }
}