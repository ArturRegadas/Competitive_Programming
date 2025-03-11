import sys

def main():
    data = sys.stdin.read()
    A, B = data.split()
    B = int(B)
    
    ans = 0
    for c in A:
        ans = (ans * 10 + (ord(c) - 48)) % B
    
    print(ans)

main()
