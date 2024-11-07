def diference(n:int, nuns:set) -> bool:
    for current in nuns:
        if n+current in nuns or (n-current)*-1 in nuns:
            return True
    return False

def bingo(ball: int, size:int, nuns:set) -> bool:
    for i in range(0, ball+1):
        if not diference(i, nuns):
            return False
    return True



def main():
    while True:
        data = input().split(' ')
        ball = int(data[0])
        size = int(data[1])

        if ball == 0 and size == 0:break;

        nuns = set(list(map(int, input().split(' '))))

        result = 'N'

        if bingo(ball, size, nuns):
            result = 'Y'
        print(result)
        
main()