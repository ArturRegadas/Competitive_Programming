radix, gas = list(map(float, input().split(' ')))
area =  (4.0/3.0) * (3.1415*(radix*radix*radix))
print(int(gas//area))