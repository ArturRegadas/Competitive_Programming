
def find(parent, vertex):
    if parent[vertex] != vertex:
        parent[vertex] = find(parent, parent[vertex])
    return parent[vertex]

def union(parent, rank, root1, root2):
    if rank[root1] > rank[root2]:
        parent[root2] = root1
    elif rank[root1] < rank[root2]:
        parent[root1] = root2
    else:
        parent[root2] = root1
        rank[root1] += 1

def kruskal(adj_list):
    vertices = list(adj_list.keys())
    edges = []


    for u in adj_list:
        for v, weight in adj_list[u].items():
            if u < v:  
                edges.append((u, v, weight))

    edges.sort(key=lambda x: x[2])

    parent = {v: v for v in vertices}
    rank = {v: 0 for v in vertices}
    total_cost = 0

    for u, v, weight in edges:
        root1 = find(parent, u)
        root2 = find(parent, v)
        
        if root1 != root2:
            union(parent, rank, root1, root2)
            total_cost += weight

    return total_cost
import time
input()
c=time.time()
while True:

    data=input().split(' ')
    if data == ['0', '0']:break
    graph={}
    for i in range(int(data[1])):
        edge=input().split(' ')
        if not edge[0] in graph:
            graph[edge[0]]={}

        graph[edge[0]][edge[1]]=int(edge[2])
        if not edge[1] in graph:
            graph[edge[1]]={}
        graph[edge[1]][edge[0]]=int(edge[2])
    cost = kruskal(graph)
    print(cost)
print(c-time.time())
