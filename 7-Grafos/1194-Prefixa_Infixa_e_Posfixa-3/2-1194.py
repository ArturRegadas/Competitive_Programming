#solucao Correta
def find_posfixo(prefixo, infixo):
    n = len(prefixo)
    posfixo = []
    pilha = [(0, 0, n)]
    
    resultado = []
    while pilha:
        pre_idx, in_start, in_end = pilha.pop()
        
        if in_start >= in_end:
            continue
        
        raiz = prefixo[pre_idx]
        in_idx = infixo.index(raiz)
        
        pilha.append((pre_idx + 1, in_start, in_idx))
        
        pilha.append((pre_idx + (in_idx - in_start) + 1, in_idx + 1, in_end))
        
        resultado.append(raiz)
    
    return ''.join(resultado[::-1])


C = int(input())

for _ in range(C):
    N, prefixo, infixo = input().split()
    posfixo = find_posfixo(prefixo, infixo)
    print(posfixo)
