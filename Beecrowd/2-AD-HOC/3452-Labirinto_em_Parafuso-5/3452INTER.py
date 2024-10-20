"""Resolucao de um labirinto simples.
Implementar resolucao com mais de um ponto de entrada consecutivamente."""

repeat=input().split(' ')
matriz=[]

nad=input()
for i in range(int(repeat[0])):
    matriz.append(input())
resp='N'
for i in range(int(repeat[1])):
    if matriz[0][i] == '0':
        fila=[[0, i]]
        processados=[]

        while fila != []:

            y=fila[0][0]
            x=fila[0][1]    
            if y == int(repeat[0])-1:
                resp='Y'
                break

            if y != 0:
                if matriz[y-1][x]=='0' and not [y-1, x] in fila and not [y-1, x] in processados:
                    fila.insert(1, [y-1, x])
                    processados.append([y-1, x])

            if x != int(repeat[1])-1 :
                if matriz[y][x+1] == '0' and not [y, x+1] in fila and not [y, x+1] in processados:
                    fila.insert(1, [y, x+1])
                    processados.append([y, x+1])
            if x != 0 :
                if matriz[y][x-1] == '0' and not [y, x-1] in fila and not [y, x-1] in processados:
                    fila.insert(1, [y, x-1])
                    processados.append([y, x-1])
            if matriz[y+1][x]=='0' and not [y+1, x] in fila and not [y+1, x] in processados:
                fila.insert(1, [y+1, x])
                processados.append([y+1, x])
            
            fila.pop(0)
            
        if resp == 'Y':
            break
print(resp)