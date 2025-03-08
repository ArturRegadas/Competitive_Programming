def MaxMin(a, b):
    if(len(a)>=len(b)):
        return True
    else:
        return False;

for i in range(int(input())):
    n, m = input().split(" ")
    ans = True
    if(MaxMin(n, m)):
        for i in range(len(n)-len(m), len(n)):
            if m[i-(len(n)-len(m))]!=n[i]:
                ans = False
                break
        print("encaixa" if ans else "nao encaixa")
    else:
        print("nao encaixa")