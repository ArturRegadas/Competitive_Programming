def calcS(points):
    if points[0] == points[1] == points[2]:
        return "trempate"
    if points[0] > points[1] and points[0] > points[2]:
        return "red"
    if points[1] > points[0] and points[1] > points[2]:
        return "green"
    if points[2] > points[1] and points[2] > points[0]:
        return "blue"
    return "empate"

repeat = int(input())
for _ in range(repeat):
    point = [0, 0, 0]
    l = int(input())
    for _ in range(l):
        m, s = input().split()
        if m == 'R':
            if s == 'G':
                point[0] += 1
            point[0] += 1
        elif m == 'G':
            if s == 'B':
                point[1] += 1
            point[1] += 1
        else:
            if s == 'R':
                point[2] += 1
            point[2] += 1
    print(calcS(point))
