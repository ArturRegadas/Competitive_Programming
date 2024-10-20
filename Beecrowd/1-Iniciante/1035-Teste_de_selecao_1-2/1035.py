nuns=input().split(' ')
a= int(nuns[0])
b= int(nuns[1])
c= int(nuns[2])
d= int(nuns[3])
if b > c and d > a and c+d > a+b and c>0 and d>0 and a%2==0:
    print("Valores aceitos")
else:
    print("Valores nao aceitos")