#o genio que fez o exercicio tem uma otima criatividade e senso que talvez não usarão py(ironia)
def dfs(u, parent, graph, dist, low, timer, ans):
    dist[u] = low[u] = timer[0]
    timer[0] += 1

    for v in graph.get(u, []):
        if dist[v] == -1:
            dfs(v, u, graph, dist, low, timer, ans)
            low[u] = min(low[u], low[v])

            if low[v] > dist[u]:
                ans[0] += 1
        elif v != parent:
            low[u] = min(low[u], dist[v])


n = int(input()) 
graph = {}


for _ in range(n):  
    c = int(input())
    nuns = list(map(int,  input().split())) 
    if not c in graph:
        graph[c] = []
    for i in nuns:
        if not i in graph[c]:
            graph[c].append(i)
        if not i in graph:
            graph[i] = []
        if not c in graph[i]:
            graph[i].append(c)
        

dist = [-1] * 60
low = [0] * 60
timer = [0]      
ans = [0]       

for i in range(n):
    if dist[i] == -1:
        dfs(i, -1, graph, dist, low, timer, ans)

print(ans[0])


