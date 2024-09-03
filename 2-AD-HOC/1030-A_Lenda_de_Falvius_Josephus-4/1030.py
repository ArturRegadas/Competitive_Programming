def josephus(n, k):
    ps=0
    for i in range(2, n+1):
        ps=(ps+k)%i
    return ps+1

for r in range(int(input())):
    info=input().split(' ')
    print(f"Case {r+1}: {josephus(int(info[0]),int(info[1]))}")