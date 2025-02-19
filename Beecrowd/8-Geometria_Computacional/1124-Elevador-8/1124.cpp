#include <bits/stdc++.h>
using namespace std;

int main(){
    double a, l, r1, r2;
    while (1){
        cin>>l>>a>>r1>>r2;
        if(a==0 && l == 0 && r1==0 && r2==0)break;
        if(2*r1>l || 2*r1>a || 2*r2>l || 2*r2>a ){
            cout<<"N\n";
        }
        else{
            if(sqrt(((l-r1-r2)*(l-r1-r2))+((a-r1-r2)*(a-r1-r2)))>=r1+r2){
                cout<<"S\n";
            }

            else{
                cout<<"N\n";
            }
        }
    }
    
    return 0;
}