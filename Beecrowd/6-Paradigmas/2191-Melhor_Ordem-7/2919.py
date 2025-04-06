import bisect
import sys

def LIS(nums):
    ans = []
    for x in nums:
        i = bisect.bisect_left(ans, x)
        if i == len(ans):
            ans.append(x)
        else:
            ans[i] = x
    return len(ans)

lines = sys.stdin.read().strip().split('\n')
i = 0
while i + 1 < len(lines):
    n = int(lines[i])
    nums = list(map(int, lines  [i + 1].strip().split()))
    if len(nums) != n:
        while len(nums) < n and i + 2 < len(lines):
            i += 1
            nums += list(map(int, lines[i + 1].strip().split()))
    print(LIS(nums))
    i += 2
