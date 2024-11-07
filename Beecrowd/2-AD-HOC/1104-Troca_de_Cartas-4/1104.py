def process(A, B, alice_cards, beatriz_cards):
    set_alice = set(alice_cards)
    set_beatriz = set(beatriz_cards)
    
    exclusive_alice = set_alice - set_beatriz
    exclusive_beatriz = set_beatriz - set_alice
    
    return min(len(exclusive_alice), len(exclusive_beatriz))

while True:
    A, B = map(int, input().split())
    
    if A == 0 and B == 0:
        break
    
    alice_cards = list(map(int, input().split()))
    beatriz_cards = list(map(int, input().split()))
    
    result = process(A, B, alice_cards, beatriz_cards)
    print(result)


