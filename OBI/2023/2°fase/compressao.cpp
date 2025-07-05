#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    string s;
    cin>>s;
    char ant = s[0];
    char current;
    int val = 1;
    for(int i =1; i<n-1; i++){
        current = s[i];
        if(current == ant){
            val+=1;
        }
        else{
            printf("%d %c ", val, ant);
            ant = current;
            val = 1;
        }
    }
    current = s[n-1];
    int carry = 0;
    if(n > 1)
        carry = 1;
    if(current == ant){
        printf("%d %c\n", val+carry, current);
    }
    else{
        printf("%d %c %d %c\n", val, ant, 1, current);
    }

    return 0;
}