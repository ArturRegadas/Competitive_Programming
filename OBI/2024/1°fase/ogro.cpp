#include <cstdio>

using namespace std;

int main(){
    int e, d;
    scanf("%d %d", &e, &d);
    if(e>d){
        printf("%d\n", e+d);
    }
    else{
        printf("%d\n", 2*(d-e));
    }

    return 0;
}