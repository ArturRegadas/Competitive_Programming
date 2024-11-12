while True:
    repeat = int(input())
    if repeat == 0:
        break

    xlog, ylog = map(int, input().split())

    for _ in range(repeat):
        xcurrent, ycurrent = map(int, input().split())

        if xcurrent == xlog or ycurrent == ylog:
            print("divisa")
        elif xcurrent > xlog and ycurrent > ylog:
            print("NE")
        elif xcurrent < xlog and ycurrent > ylog:
            print("NO")
        elif xcurrent < xlog and ycurrent < ylog:
            print("SO")
        else:
            print("SE")
