#matriz de adjacencia, classes, dfs
class graph :
    def __init__(self, value):
        self.Graph=[[0 for g in range(value)]for i in range(value)]
        self.InNum={}
        self.contador = 0
        self.size=value

    def Convert(self, son, parent1, parent2):
        if not son in self.InNum:
            self.InNum[son]=self.contador
            self.contador+=1
        if not parent1 in self.InNum:
            self.InNum[parent1]=self.contador
            self.contador+=1
        if not parent2 in self.InNum:
            self.InNum[parent2]=self.contador
            self.contador+=1

    def Add(self, son, parent1, parent2):
        p1=self.InNum[son]
        p2=self.InNum[parent1]
        p3=self.InNum[parent2] 
        self.Graph[p1][p2]=1
        self.Graph[p1][p3]=1

    def FindParents(self, par1) -> int:
        start=self.InNum[par1]
        queue=[start]
        processed=[]
        conect = self.Graph
        while queue:
            current = queue[0]
            for i in range(0, self.size):
                if conect[current][i] == 1:
                    queue.append(i)
            queue.pop(0)
            processed.append(current)
        if len(processed) >=4:
            return (processed[len(processed)-1], processed[len(processed)-2], processed[len(processed)-3], processed[len(processed)-4])

        elif len(processed)>=2:
            return (processed[len(processed)-1], processed[len(processed)-2])
        else:
            return (processed[0], processed[0])
                
        


def main():
    data=input().split(' ')
    
    matriz=graph(int(data[0]))
    for repeat in range(0, int(data[1]), +1):
        edges=input().split(' ')
        matriz.Convert(edges[2], edges[0], edges[1])
        matriz.Add(edges[2], edges[0], edges[1])

    
    for repeat in range(0, int(data[2]), +1):
        relationship=input().split(' ')
        prf1=matriz.FindParents(relationship[0])
        prf2=matriz.FindParents(relationship[1])
        if prf1[0] in prf2 or prf1[1] in prf2 or prf2[0] in prf1 or prf2[1] in prf1:
            print("verdadeiro")
        else:
            print("falso")
        

main()
    
    
