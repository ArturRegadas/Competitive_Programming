i=1
while(True):
    try:
        fp, fh = list(map(int, input().split(' ')))
        edge = (fp*5+fh*6)/2
        vertex = 2-(fp+fh)+edge
        print(f"Molecula #{i}.:.")
        print(f"Possui {int(vertex)} atomos e {int(edge)} ligacoes\n")
        i+=1

    except:
        break