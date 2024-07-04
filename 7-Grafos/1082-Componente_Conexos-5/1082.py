letras1="a b c d e f g h i j k l m n o p q r s t u v w x y z"
letras1=letras1.split(' ')
for h in range(int(input())):
    repeat=input().split(' ')
    fila_geral=letras1[:int(repeat[0])]
    grafo={}
    cont=0
    for i in range(int(repeat[1])):
        ligacoes=input().split(' ')
        if not ligacoes[0] in grafo:
            grafo[ligacoes[0]]=[]
        grafo[ligacoes[0]].append(ligacoes[1])

        if not ligacoes[1] in grafo:
            grafo[ligacoes[1]]=[]
        grafo[ligacoes[1]].append(ligacoes[0])
    
    for i in fila_geral:
        if not i in grafo:
            grafo[i]=[]
    otext1=[]
    fila_geral.sort()
    while fila_geral !=[]:
        otext=fila_geral[0]+','
        inicio=fila_geral[0]
        fila=[inicio]
        processados=[]
        while fila != []:
            atual=fila[0]
            for g in grafo[atual]:
                if not g in fila and not g in processados:
                    fila.append(g)
                    otext=otext+g+','
            processados.append(atual)
            fila.pop(0)
        for g in processados:
            fila_geral.remove(g)
        otext1.append(otext)
    print(f"Case #{h+1}:")
    listres=[]
    for i in otext1:
        result=i.split(',')
        result.sort()
        result.pop(0)
        listres.append(result)
    
    for i in listres:
        for g in i:
            print(g, end=',')
        print('')

    print(f"{len(otext1)} connected components")
    print('')
