for g in range(int(input())):
    str=input()
    n=''
    for i in range(len(str)-1, -1,-1):
        if str[i].isalpha():
            n+=chr(ord(str[i])+3)
        else:
            n+=str[i]
    m=n[:len(n)//2]
    for i in n[len(n)//2:]:
        m+=chr(ord(i)-1)
    print(m)
