while True:    
    nuns=input().split(' ')
    nun1=int(nuns[0])
    nun2=int(nuns[1])
    if nun1 <= 0 or nun2 <=0:
        break
    lista=0
    list=[]
    if nun1 < nun2:
        for i in range(nun1, nun2+1):
            lista+=i
            list.append(i)

    else:
        for i in range(nun1, nun2-1, -1):
            lista+=i
            list.append(i)
    
        list.reverse()
    for i in list: print(i, end=" ")
    print(f"Sum={lista}")