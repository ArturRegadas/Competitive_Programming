import sys

def processa_estacionamento(c, eventos):
    estacionamento = [0] * c 
    veiculos = {} 
    espacos_livres = [(0, c)]  
    faturamento = 0

    for evento in eventos:
        dados = evento.split()
        if dados[0] == 'C': 
            placa, tamanho = int(dados[1]), int(dados[2])
            posicao = -1
            

            for i, (inicio, comprimento) in enumerate(espacos_livres):
                if comprimento >= tamanho:
                    posicao = inicio
                    espacos_livres.pop(i)
                    if comprimento > tamanho:
                        espacos_livres.insert(i, (inicio + tamanho, comprimento - tamanho))
                    break
            
            if posicao != -1:  
                for j in range(posicao, posicao + tamanho):
                    estacionamento[j] = 1
                veiculos[placa] = (posicao, tamanho)
                faturamento += 10
        
        elif dados[0] == 'S':  
            placa = int(dados[1])
            if placa in veiculos:
                posicao, tamanho = veiculos.pop(placa)
                for j in range(posicao, posicao + tamanho):
                    estacionamento[j] = 0
                
           
                nova_lista = []
                inserido = False
                for inicio, comprimento in espacos_livres:
                    if inicio == posicao + tamanho:
                        posicao, tamanho = posicao, tamanho + comprimento
                    elif posicao == inicio + comprimento:
                        posicao, tamanho = inicio, tamanho + comprimento
                    else:
                        nova_lista.append((inicio, comprimento))
                
                nova_lista.append((posicao, tamanho))
                espacos_livres = sorted(nova_lista)
    
    return faturamento


entrada = sys.stdin.read().strip().split("\n")
i = 0
resultados = []

while i < len(entrada):
    c, n = map(int, entrada[i].split())
    eventos = entrada[i + 1: i + 1 + n]
    i += n + 1
    resultados.append(str(processa_estacionamento(c, eventos)))

print("\n".join(resultados))
