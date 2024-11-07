#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int process_case(int A, int B, vector<int>& alice_cards, vector<int>& beatriz_cards) {
    
    set<int> set_alice(alice_cards.begin(), alice_cards.end());
    set<int> set_beatriz(beatriz_cards.begin(), beatriz_cards.end());
    
    
    set<int> exclusive_alice, exclusive_beatriz;
    
    
    for (int card : set_alice) {
        if (set_beatriz.find(card) == set_beatriz.end()) {
            exclusive_alice.insert(card);
        }
    }

    for (int card : set_beatriz) {
        if (set_alice.find(card) == set_alice.end()) {
            exclusive_beatriz.insert(card);
        }
    }
    
    
    return min(exclusive_alice.size(), exclusive_beatriz.size());
}

int main() {
    while (true) {
        int A, B;
        cin >> A >> B;
        
        if (A == 0 && B == 0) {
            break;
        }
        
        vector<int> alice_cards(A);
        for (int i = 0; i < A; ++i) {
            cin >> alice_cards[i];
        }
        
        vector<int> beatriz_cards(B);
        for (int i = 0; i < B; ++i) {
            cin >> beatriz_cards[i];
        }
        

        int result = process_case(A, B, alice_cards, beatriz_cards);
        cout << result << endl;
    }
    
    return 0;
}
