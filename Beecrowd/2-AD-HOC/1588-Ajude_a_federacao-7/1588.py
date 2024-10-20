for i in range(int(input())):
    times={}
    info=input().split(' ')
    for g in range(int(info[0])):
        times[input()]=[0,0,0]
    for g in range(int(info[1])):
        jogo=input().split(' ')
        if int(jogo[0]) > int(jogo[2]):
            times[jogo[1]][0]+=3
            times[jogo[1]][1]+=1
        elif int(jogo[0]) < int(jogo[2]):
            times[jogo[3]][0]+=3
            times[jogo[3]][1]+=1
            
        else:
            times[jogo[3]][0]+=1
            times[jogo[1]][0]+=1
                
            
        times[jogo[1]][2]+=1*int(jogo[0])
        times[jogo[3]][2]+=1*int(jogo[2])
        
        times_ordenados = sorted(times.items(), key=lambda item: (-item[1][0], -item[1][1], -item[1][2]))
    for a in times_ordenados:
        print(a[0])


            