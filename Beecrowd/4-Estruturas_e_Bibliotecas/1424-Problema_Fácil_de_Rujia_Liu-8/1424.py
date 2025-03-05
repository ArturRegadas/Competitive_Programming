import sys

for linha in sys.stdin:
    ocurrence = {}
    n, m = map(int, linha.split()) 
    array = list(map(int, input().split())) 
    idx=1
    for i in array:
        if not i in ocurrence:
            ocurrence[i] = []
        ocurrence[i].append(idx)
        idx+=1
    for c in range(m):
        init, wanted = map(int, input().split( ))
        print(0 if not wanted in ocurrence or len(ocurrence[wanted])<init else ocurrence[wanted][init-1])
        