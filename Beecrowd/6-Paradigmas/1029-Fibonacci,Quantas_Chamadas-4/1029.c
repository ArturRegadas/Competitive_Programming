#include <stdio.h>
int memo[51];
int call[51];


int fib(int a){
    if(memo[a]==0){
        memo[a] = fib(a-1) + fib(a-2);
    }
    return memo[a];
}
int calls(int a){
    if(call[a]==0){
        call[a] = calls(a-1)+calls(a-2)+1;
    }
    return call[a];
}

int main(){
    memo[0]=1;
    memo[1]=1;
    call[0]=1;
    call[1]=1;
    int size;
    int n;
    scanf("%d", &size);
    for(int i =0;i<size;i++){
        scanf("%d",&n);
        printf("fib(%d) = %d calls = %d\n", n, calls(n)-1, fib(n-1));
    }
    
    return 0;
}