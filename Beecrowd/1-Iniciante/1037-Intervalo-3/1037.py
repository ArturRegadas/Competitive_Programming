
onun=float(input())

if onun>=0 and onun <=25:
    print("Intervalo [0,25]")

elif onun>25 and onun <=50:
    print("Intervalo (25,50]")

elif onun>50 and onun <=75:
    print("Intervalo (50,75]")

elif onun>75 and onun <=100:
    print("Intervalo (75,100]")

else:
    print("Fora de intervalo")