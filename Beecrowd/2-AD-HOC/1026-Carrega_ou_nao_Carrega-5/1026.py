import sys
import math

def bin_representation(n, length=33):
    array = [0] * length
    indic = length - 1
    while n > 0:
        resto = n % 2
        n = n // 2
        array[indic] = resto
        indic -= 1
    return array

input = sys.stdin.read().strip().split()
index = 0

while index < len(input):
    if index + 1 >= len(input):
        break

    n1 = float(input[index])
    n2 = float(input[index + 1])
    index += 2

    array1 = bin_representation(int(n1))
    array2 = bin_representation(int(n2))

    resultado = 0
    for i in range(33):
        cv = array1[i] + array2[i]
        if cv == 2:
            cv = 0
        resultado += cv * (2 ** (32 - i))

    print(int(resultado))


