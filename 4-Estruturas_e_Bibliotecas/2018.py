print("Quadro de Medalhas")
times={}
pontuacao={}
indice={}
while True:
    try:
        nad=input()
        
        ven=input()
        if not ven in times:
            times[ven]=[0,0,0]
            pontuacao[ven]=0
        times[ven][0]+=1
        pontuacao[ven]+=99999999
        
        ven1=input()
        if not ven1 in times:
            times[ven1]=[0,0,0]
            pontuacao[ven1]=0

        times[ven1][1]+=1
        pontuacao[ven1]+=10000
        
        ven2=input()
        if not ven2 in times:
            times[ven2]=[0,0,0]
            pontuacao[ven2]=0

        times[ven2][2]+=1
        pontuacao[ven2]+=1
    except:
        break

    
pontuacao = sorted(pontuacao.items(), key= lambda item : item[0])
dic={}
for i in range(0, len(pontuacao)):
    dic[pontuacao[i][0]]=pontuacao[i][1]
for i in sorted(dic, key=dic.get, reverse=True):
    print(i, times[i][0],times[i][1],times[i][2])