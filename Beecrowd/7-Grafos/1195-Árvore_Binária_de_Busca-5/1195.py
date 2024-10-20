def insere_arvore(tree, root, value):
    if value < root:
        if tree[root][0] == -1:
            tree[root][0] = value
            tree[value] = [-1, -1]
        else:
            insere_arvore(tree, tree[root][0], value)
    else:
        if tree[root][1] == -1:
            tree[root][1] = value
            tree[value] = [-1, -1]
        else:
            insere_arvore(tree, tree[root][1], value)

def prefixo(tree, root, resultado):
    if root != -1:
        resultado.append(root)
        prefixo(tree, tree[root][0], resultado)
        prefixo(tree, tree[root][1], resultado)

def infixo(tree, root, resultado):
    if root != -1:
        infixo(tree, tree[root][0], resultado)
        resultado.append(root)
        infixo(tree, tree[root][1], resultado)

def posfixo(tree, root, resultado):
    if root != -1:
        posfixo(tree, tree[root][0], resultado)
        posfixo(tree, tree[root][1], resultado)
        resultado.append(root)

def resolver_casos(casos):
    for caso in range(1, casos + 1):
        n = int(input())
        valores = list(map(int, input().split()))
        tree = {}
        root = valores[0]
        tree[root] = [-1, -1]
        for valor in valores[1:]:
            insere_arvore(tree, root, valor)
        pre_resultado = []
        in_resultado = []
        post_resultado = []
        prefixo(tree, root, pre_resultado)
        infixo(tree, root, in_resultado)
        posfixo(tree, root, post_resultado)
        print(f"Case {caso}:")
        print("Pre.:", " ".join(map(str, pre_resultado)))
        print("In..:", " ".join(map(str, in_resultado)))
        print("Post:", " ".join(map(str, post_resultado)))
        print()

c = int(input())
resolver_casos(c)
