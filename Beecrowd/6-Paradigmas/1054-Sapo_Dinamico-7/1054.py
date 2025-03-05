t = int(input().strip()) 
for case in range(1, t + 1):
    n, d = map(int, input().split())
    stones = [(0, 0)]  
    stones.append((d, 0)) 
    if(n>0):
        command = input().split()
        for i in command:
            size, pos = i.split('-')
            stones.append((int(pos), 1 if size == 'S' else 0))

    stones.sort() 

    ans = 0
    p = 0
    c = 1  


    for i in range(1, len(stones)):
        pos, is_small = stones[i]
        if is_small == 0: 
            ans = max(ans, abs(p - pos))
            p = pos
        elif is_small == 1:
            if c:
                stones[i] = (pos, 2) 
                ans = max(ans, abs(p - pos))
                p = pos
            c ^= 1  #xor, no caso inverte


    for i in range(len(stones) - 2, -1, -1):
        pos, is_small = stones[i]
        if is_small <= 1: 
            ans = max(ans, abs(p - pos))
            p = pos

    print(f"Case {case}: {ans}")

