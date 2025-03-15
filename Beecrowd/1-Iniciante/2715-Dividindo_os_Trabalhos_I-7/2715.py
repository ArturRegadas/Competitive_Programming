import sys
for n in sys.stdin:
    nums=list(map(int, input().strip().split()))
    l = 0
    r = int(n)-1
    Ra = Bob = 0
    while(l<r):
        if(Ra+nums[l] <= Bob+nums[r]):
            Ra+=nums[l]
            l+=1
        else:
            Bob +=nums[r]
            r-=1
    Ra+= nums[l] if Ra<Bob else nums[l]*-1
    print(abs(Ra-Bob))