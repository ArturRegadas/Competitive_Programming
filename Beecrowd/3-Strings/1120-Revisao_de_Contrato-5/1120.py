while True:
    data = input().split(' ')
    if data == ['0', '0']:break
    digito=int(data[0])
    numero=list(data[1])
    while data[0] in numero:
        numero.remove(data[0])
    if numero == []:
        print(0)
    else:    
        result=''.join(numero)
        print(int(result))