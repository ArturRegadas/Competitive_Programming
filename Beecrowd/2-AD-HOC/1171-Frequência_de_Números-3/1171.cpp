#include <bits/stdc++.h>
#define MAXN (int) 1e8
using namespace std;
int freq[MAXN];

int main(){
    set<int> nuns;
    int size, current;scanf("%d", &size);
    for(int i =0;i<size;i++){
        scanf("%d", &current);
        nuns.insert(current);
        freq[current]++;
    }
    for(int i : nuns){
        printf("%d aparece %d vez(es)\n", i, freq[i]);
    }
    return 0;
}