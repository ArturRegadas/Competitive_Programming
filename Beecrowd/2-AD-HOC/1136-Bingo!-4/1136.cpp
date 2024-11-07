#include <iostream>
#include <set>
using namespace std;

bool diference(int n, set<int>nuns){
    for (int current : nuns){
        //equcao modular do primeiro grau kkkk
        if(nuns.find(n+current) != nuns.end() | nuns.find((n-current)*-1) != nuns.end()){
            return true;
        }
    }
    return false;
}

bool bingo(int ball,int size, set<int>nuns){

    for(int i = 0; i<ball+1; i++){
        if (diference(i, nuns)==false){
            return false;
        }
    }
    return true;
    

}


int main(){
    
    int ball, help, size;
    char result;

    while (1){

        cin>>ball>>size;

        if (ball ==0 && size == 0)break;

        set<int>nuns = {};

        for(int i = 0; i<size; i++){
            cin>>help;
            nuns.insert(help);
        }

        result = 'N';
        if (bingo(ball, size, nuns)){
            result = 'Y';
        }

        cout<<result<<"\n";

        

    }

    return 0;
}