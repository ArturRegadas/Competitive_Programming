repeat = input().split(' ')
matriz=[]
for i in range(int(repeat[0])):
    matriz.append(input())
cont=0
for y in range(len(matriz)):#[y]
    for x in range(len(matriz[i])):#[x]
        thebol=True
        if matriz[y][x] == '#':
            if y != 0:
                if matriz[y-1][x]=='.':
                    thebol=False
                    cont+=1
            else:
                if thebol:
                    thebol=False
                    cont+=1
            if y != int(repeat[0])-1 and thebol:
                if matriz[y+1][x]=='.':
                    thebol=False
                    cont+=1
            else:
                if thebol:
                    thebol=False
                    cont+=1
            if x != 0 and thebol:
                if matriz[y][x-1]=='.':
                    thebol=False
                    cont+=1
            else:
                if thebol:
                    thebol=False
                    cont+=1
            if x != int(repeat[1])-1 and thebol:
                if matriz[y][x+1]=='.':
                    thebol=False
                    cont+=1
            else:
                if thebol:
                    thebol=False
                    cont+=1
print(cont)

