#include <iostream>
using namespace std;

int main(){
    int size;scanf("%d", &size);
    char command[4];
    for(int i =0;i<size;++i){
        scanf(" %s", command);
        if((int)command[0]-'0' == (int)command[2]-'0')printf("%d\n", ((int)command[0]-'0') * ((int)command[2]-'0'));
        else if ((int)command[1]<97)printf("%d\n", ((int)command[2]-'0') - ((int)command[0]-'0'));
        else printf("%d\n", ((int)command[2]-'0') + ((int)command[0]-'0'));
    }

    return 0;
}