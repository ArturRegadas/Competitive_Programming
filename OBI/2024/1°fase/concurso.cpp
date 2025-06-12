#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int s, n, v[1000];
    scanf("%d%d", &s, &n);
    for(int i =0; i<s;i++)scanf("%d", &v[i]);
    sort(v, v+s);
    printf("%d\n", v[s-n]);

    return 0;
}