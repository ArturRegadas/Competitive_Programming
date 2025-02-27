import sys

ans=[]
for line in sys.stdin:
    axu = 0
    result = []

    for c in line:  
        if c == ' ':
            result.append(" ")
            continue

        axu += 1
        result.append(c.upper() if axu % 2 == 1 else c.lower())

    ans.append("".join(result))
print("".join(ans), end="")
