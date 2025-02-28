repeat = int(input())
for _ in range(repeat):
    ans = 0
    size = int(input())
    disparos = list(map(int, input().split()))
    jumps = input()

    for i in range(size):
        if (jumps[i] == 'S' and disparos[i] <= 2) or (jumps[i] == 'J' and disparos[i] > 2):
            ans += 1

    print(ans)
