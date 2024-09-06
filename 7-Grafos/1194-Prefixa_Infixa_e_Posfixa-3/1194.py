#Resolucao Porca, e incorreta, ma criacao de casos de teste

repeat=int(input())

def p_i(infixa, proc, size) -> int:
    for i in range(0, size, +1):
        if infixa[i]==proc:
            return i-1

    
for r in range(0, repeat, +1):
    data=input().split(' ')
    prefixa=data[1]
    infixa=data[2]
    
    raiz=prefixa[0]
    result=""

    passed=True

    qtd=int(data[0])
    nad=False

    qtd2=p_i(infixa, prefixa[0], qtd)

    c=0
    passed2=True

    for i in range(0, int(data[0]), +1):
        if nad:
            if passed:
                c+=1
                passed=False
            else:
                qtd-=1
                passed=True
                c+=1
        elif infixa[c] == raiz:
            nad=True
            c+=1
        else:
            if passed2:
                result+=infixa[c]
                passed2=False
                c+=1
            else:
                if infixa[qtd2-1]==infixa[c]:
                    result+=infixa[qtd2]+infixa[qtd2-1]
                    break
                else:
                    result+=infixa[qtd2]
            
                passed2=True
                c+=1

    passed=True

    qtd=int(data[0])
    nad=False

    c=0

    for i in range(0, int(data[0]), +1):
        if nad:
            if passed:
                result+=infixa[c]
                c+=1
                passed=False
            else:
                result+=infixa[qtd-1]
                qtd-=1
                passed=True
        elif infixa[c] == raiz:
            nad=True
            c+=1
        else:
            c+=1
    result+=raiz
    print(result)
