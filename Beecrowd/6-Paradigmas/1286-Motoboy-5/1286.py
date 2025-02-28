


while(True):
    pedidos=int(input())
    if(pedidos==0):break
    tmp = [0]*pedidos
    pizzas= [0]*pedidos
    maxPizza = int(input())
    for i in range(pedidos):
        tmp[i], pizzas[i] = map(int, input().split())

    dp = [[0] * (maxPizza + 1) for _ in range(pedidos + 1)]
    for i in range(pedidos):
        for j in range(maxPizza+1):
            if(j >= pizzas[i]) :
                dp[i+1][j] = max(dp[i][j], dp[i][j - pizzas[i]] + tmp[i])
            else:
                dp[i+1][j] = dp[i][j] 


    print(f"{dp[pedidos][maxPizza]} min.")

