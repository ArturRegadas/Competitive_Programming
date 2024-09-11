def maxprice(price, weight, size, repeat) -> int:

    maxinum=[0 for i in range(0, size+1, +1)]

    for i in range(0, repeat):
        value_p=price[i]
        value_w=weight[i]

        for w in range(size, value_w-1, -1):
            maxinum[w]=max(maxinum[w], maxinum[w-value_w]+value_p)
        
    return maxinum[size]


while True:
    repeat=int(input())
    if repeat == 0:
        break
    price=[]
    weight=[]
    for r in range(0, repeat, +1):
        data=input().split(' ')

        price.append(int(data[0]))
        weight.append(int(data[1]))

    size=int(input())
    print(maxprice(price, weight, size, repeat))


