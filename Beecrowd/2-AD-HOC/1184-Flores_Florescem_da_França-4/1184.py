while True:
    command = input()
    if command == "*":break
    command = command.split(' ')
    ans = "Y"
    f = command[0][0].upper()
    for i in range(1, len(command)):
        if command[i][0].upper() != f:
            ans = "N"
            break
    print(ans)