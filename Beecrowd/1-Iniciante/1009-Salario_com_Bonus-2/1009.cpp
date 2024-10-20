#include <iostream>
#include <string>
#include <cstdio>
int main() {
    std::string a;
    double b, c;
    std::cin>>a>>b>>c;
    std::printf("TOTAL = R$ %.2f\n",b+c*15/100);
 
    return 0;
}