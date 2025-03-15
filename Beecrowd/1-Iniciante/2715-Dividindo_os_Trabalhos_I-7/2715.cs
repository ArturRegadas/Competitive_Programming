using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
public class Solution{
    public static List<int> splitString(string a){
        List<int> ans = new List<int>();
        string current = "";
        bool Was = true;
        foreach(char i in a){
            if(i != ' '){
                current+=i;
                Was = false;
            }
            else{
                if(!Was){
                    ans.Add(int.Parse(current));
                    Was = true;
                }
                current="";
            }
        }
        ans.Add(int.Parse(current));
        return ans;
    }
    public static void Main(){
        while(true){
            try{
                int n = int.Parse(Console.ReadLine().Trim());
                List<int> nums = splitString(Console.ReadLine().Trim());
                while(nums.Count < n)nums.AddRange(splitString(Console.ReadLine().Trim()));
                int l =0;
                int r = n-1;
                long Ra = 0;
                long La = 0;
                while(l<r){
                    if(La + nums[l] < Ra+nums[r]){
                        La+=nums[l];
                        l++;
                    }
                    else{
                        Ra+=nums[r];
                        r--;
                    }
                }
                if(Ra < La) Ra += nums[r];
                else La +=nums[l];
                Console.WriteLine(Math.Abs(La-Ra));
                nums.Clear();
            }
            catch(Exception e){
                break;
            }
        }
    }
}