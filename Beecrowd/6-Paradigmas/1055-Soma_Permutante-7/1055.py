for r in range(int(input())):
    nuns=list(map(int, input().split(' ')[1:]))
    nuns.sort()
    size = len(nuns)
    midle = size//2
    if(size%2==0):midle-=1
    ans = 0;
    idx=0;
    newNuns = [0]*size
    for i in range(size-1, midle, -1):
        newNuns[idx] = nuns[i-midle-1];
        idx+=1
        newNuns[idx] = nuns[i]
        idx+=1
    if(size%2==1):newNuns[idx] = nuns[midle]
    for i in range(1, size):ans+= abs(newNuns[i-1] - newNuns[i])
    
    nuns.reverse()
    idx=0;
    newNuns2 = [0]*size
    ans2=0
    for i in range(size-1, midle, -1):
        newNuns2[idx] = nuns[i-midle-1];
        idx+=1
        newNuns2[idx] = nuns[i]
        idx+=1
    if(size%2==1):newNuns2[idx] = nuns[midle]
    for i in range(1, size):ans2+= abs(newNuns2[i-1] - newNuns2[i])
    print(f"Case {r+1}: {max(ans, ans2)}")
