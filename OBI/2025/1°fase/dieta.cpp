#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    int p, g, c;
    vector<int> ref;
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; i++){
        scanf("%d %d %d", &p, &g, &c);
        ref.push_back((p*4)+(g*9)+(c*4));
    }
    sort(ref.begin(), ref.end());

    int cal = 0;
    for(int i : ref){
        if(cal + i <= m)
            cal+=i;
        else
            break;
    }

    printf("%d\n", m-cal);



    return 0;
}