
#include <bits/stdc++.h>


using namespace std;

int main(){
    double s;
    const double c= sin(108*(M_PI/180))/sin(63*(M_PI/180));

    while(cin>>s){
        printf("%.10lf\n",s*c);
    }

    return 0;
}