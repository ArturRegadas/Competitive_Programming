size = int(input())

for _ in range(size):
    p1, p2 = input().split()

    minu, maxi = sorted([p1, p2]) 
    ans = []

    for i in range(len(minu)):
        ans.append(p1[i])
        ans.append(p2[i])

    ans.extend(maxi[len(minu):])  

    print("".join(ans))
