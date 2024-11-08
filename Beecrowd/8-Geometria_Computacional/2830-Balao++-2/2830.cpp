#include <iostream>
using namespace std;

int main(){

    double radix, gas;
    
    cin>>radix>>gas;
    
    double area =  (4.0/3.0) * (3.1415*(radix*radix*radix));
    
    cout<<(int)(gas/area)<<"\n";
    
    return 0;
}