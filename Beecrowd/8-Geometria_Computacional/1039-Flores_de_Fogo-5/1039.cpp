
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    double r1, x1, y1, r2, x2, y2, distance;
    while(cin>>r1>>x1>>y1>>r2>>x2>>y2){
        distance = sqrt((abs(x1-x2)*abs(x1-x2))+(abs(y1-y2)*abs(y1-y2)));
        if(distance+r2<=r1){
            cout<<"RICO\n";
        }
        else{
            cout<<"MORTO\n";
        }
    }
}