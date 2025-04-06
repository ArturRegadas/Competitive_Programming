using System;
using System.Collections.Generic;

class Program
{
    static int LowerBound(List<int> list, int target)
    {
        int l = 0, r = list.Count;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (list[mid] < target) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    static int LIS(List<int> nums)
    {
        List<int> lis = new List<int>();
        foreach (int x in nums)
        {
            int idx = LowerBound(lis, x);
            if (idx == lis.Count) lis.Add(x);
            else lis[idx] = x;
        }
        return lis.Count;
    }

    static void Main()
    {
        List<string> lines = new List<string>();
        string line;
        while ((line = Console.ReadLine()) != null)
        {
            if (line.Trim() != "") lines.Add(line);
        }

        int i = 0;
        while (i + 1 < lines.Count)
        {
            int n = int.Parse(lines[i]);
            i++;
            List<int> nums = new List<int>();

            while (nums.Count < n && i < lines.Count)
            {
                string[] parts = lines[i].Trim().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
                foreach (var part in parts)
                    nums.Add(int.Parse(part));
                i++;
            }

            Console.WriteLine(LIS(nums));
        }
    }
}
