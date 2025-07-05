n=int(input())
aP = ''
aS = -1
s = int(input())
for _ in range(n):
    p = input()
    for i in range(s):
        cs = input()
        if not "I" in cs :
            cs = float(cs)
            if aS < cs:
                aP = p
                aS = cs
print(aP)
print(f"{aS:.2f}")

