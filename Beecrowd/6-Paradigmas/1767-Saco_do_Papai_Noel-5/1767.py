def minkg(maxinum, maxp, size) -> int:
    l=size
    while maxinum[l] == maxp:
        l-=1
    return l+1

def maxprice(price, weight, size, repeat) -> int:

    maxinum=[0 for i in range(0, size+1, +1)]
    maxitens=maxinum[:]
    for i in range(0, repeat):
        value_p=price[i]
        value_w=weight[i]
        for w in range(size, value_w-1, -1):
            if maxinum[w-value_w]+value_p > maxinum[w]:
                maxinum[w]=maxinum[w-value_w]+value_p
                maxitens[w]=maxitens[w-value_w]+1

    toyskg=minkg(maxinum, maxinum[size], size)
    return maxinum[size], maxitens[size], toyskg

for r in range(0, int(input())):
    prices=[]
    weights=[]
    repeat=int(input())
    for i in range(repeat):
        data=input().split(' ')
        prices.append(int(data[0]))
        weights.append(int(data[1]))
    ma, tot, toyskg=maxprice(prices, weights, 50, repeat)
    
    print(ma, "brinquedos")
    print(f"Peso: {toyskg} kg")
    print(f"sobra(m) {repeat-tot} pacote(s)")
    print("")
