data=input().split(' ')
qtd_titans=int(data[0])
tam_mur=int(data[1])
atack=input()
p=input().split(' ')
price=[int(p[0]),int(p[1]),int(p[2])]

result=1


muralhas=[tam_mur]
contado_G=0
contado_M=0
contado_P=0

for i in atack:
    if i == 'G':
        atual=price[2]
        contador=contado_G
    elif i == 'M':
        atual=price[1]
        contador=contado_M
    else:
        atual=price[0]
        contador=contado_P
    mur=muralhas[contador]
    while atual > mur:
        contador+=1
        if contador == len(muralhas):
            muralhas.append(tam_mur)
            result+=1
        
        mur=muralhas[contador]
    if i == 'G':
        contado_G=contador
    elif i == 'M':
        contado_M=contador
    else:
        contado_P=contador
    muralhas[contador]-=atual
print(result)