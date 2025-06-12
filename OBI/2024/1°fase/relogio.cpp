#include <cstdio>

using namespace std;

int main(){
    int h, m, s, i;
    int nh, nm, ns;
    scanf("%d%d%d%d", &h, &m, &s, &i);
    ns = (s+i)%60;
    i = (s+i)/60;
    nm = (m+i)%60;
    i = (m+i)/60;
    nh = (h+i)%24;
    printf("%d\n%d\n%d\n", nh, nm, ns);

    return 0;
}