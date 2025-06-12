#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int n, f;
    scanf("%d%d", &n, &f);
    printf("%.0f\n", floor(log(n) / log(f)));
    return 0;
}