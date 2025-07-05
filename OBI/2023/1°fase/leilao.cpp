#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    string p, ansP;
    int val, ansV;
    ansV=-1;
    for(int i =0; i< n; i++){
        cin>>p>>val;
        if(val > ansV){
            ansP = p;
            ansV = val;   
        }
    }
    cout<<ansP<<endl<<ansV<<endl;
    return 0;
}