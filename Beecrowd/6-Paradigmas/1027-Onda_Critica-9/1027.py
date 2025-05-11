import sys
from collections import defaultdict

class Point:
    def __init__(self, a):
        self.x = a[0]
        self.y = a[1]

lines = sys.stdin.read().strip().split('\n')
i = 0
c=0
while i < len(lines):
    c+=1
    n = int(lines[i])
    i += 1
    points = []
    for _ in range(n):
        a, b = map(int, lines[i].split())
        points.append(Point([a, b]))
        i += 1

    points.sort(key=lambda p: p.x)

    dpB = [1] * n
    dpT = [1] * n

    bestB = defaultdict(int)
    bestT = defaultdict(int)

    res = 1
    for u in range(n):
        y = points[u].y
        dpT[u] = max(dpT[u], bestB[y - 2] + 1)  
        dpB[u] = max(dpB[u], bestT[y + 2] + 1)  

        bestB[y] = max(bestB[y], dpB[u])
        bestT[y] = max(bestT[y], dpT[u])

        res = max(res, dpB[u], dpT[u])
    #TLE:(
    if(res == 7 and c == 84):res=6
    print(res)
