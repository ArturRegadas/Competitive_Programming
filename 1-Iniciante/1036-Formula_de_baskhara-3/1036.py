nuns=input().split(' ')

a=float(nuns[0])
b=float(nuns[1])
c=float(nuns[2])
if a == 0 or b*b-4*a*c <0:
    print("Impossivel calcular")
else:    
    print(f"R1 = {(-b+(b*b-4*a*c)**0.5)/(2*a):.5f}")
    print(f"R2 = {(-b-(b*b-4*a*c)**0.5)/(2*a):.5f}")