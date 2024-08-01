for _ in range(int(input())):
    graph={}
    neighs={'0':[]}
    repeat=input().split()
    for i in range(int(repeat[1])):
        edge=input().split()
        edge1=edge[0]
        if not edge1 in graph:
            graph[edge1]=[]
        if not edge[1] in graph:
            graph[edge[1]]=[]
        graph[edge1].append(edge[1])

        if not edge[1] in neighs:
            neighs[edge[1]]=[]
        if not edge[0] in neighs:
            neighs[edge[0]]=[]
        neighs[edge[1]].append(edge[0])
        
    fila=[]
    for i in graph:
        fila.append(int(i))
    fila.sort()
    omenor=fila[0]
    arest=[]
    cont={}
    queue = [str(omenor)]
    current=queue[0]
    passos=[]
    visited=[]
    heiht={str(omenor):1}
    processed=[str(omenor)]
    pill=False
    nad=1
    j=False
    print(f"Caso {_+1}:")
    while fila:
        omenor=fila[0]
        queue = [str(omenor)]
        path={str(omenor):[1]}
        visited=[]
        nad=1
        current=queue[0]
        j=False
        heiht[current]=1
        while queue:
            current=queue[0]
            
            if neighs[current] != []:
                for i in neighs[current]:
                    if i in visited:
                        pill=True
                    else:
                        pill=False
                        break
            if pill:
                processed.append(current)
                pill=False
            

            h=[]
            for i in graph[current]:
                if not i in processed:
                    h.append(i)
                    if not i in path:
                        path[i]=[]
                    path[i].append(current)
                    if not i in heiht or not current in graph[i]:
                        heiht[i]=heiht[current]+1
            h.sort(reverse=True)

            for i in h:
                queue.insert(1,i)

            
            
            if not current in visited:
                visited.append(current)
                
                fila.remove(int(current))
            
            if not current in cont:
                cont[current]=0
            cont[current]+=1
            
            queue.pop(0)
            if not [path[current][-1], current] in arest:
                if j:
                    print(f"{'  '*heiht[path[current][-1]]}{path[current][-1]}-{current}", end='')
                    if cont[current] <= 1:
                        print(f" pathR(G,{current})")
                    else:
                        print()
            j=True
            arest.append([path[current][-1], current])
            path[current].pop()
        print()
print()