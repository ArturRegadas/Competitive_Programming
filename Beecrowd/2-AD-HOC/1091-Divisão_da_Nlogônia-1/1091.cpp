#include <iostream>

using namespace std;

int main(){
    int repeat;
    int xlog, ylog;
    int xcurrent, ycurrent;

    while(1){
        cin>>repeat;
        if(!repeat)break;

        cin>>xlog>>ylog;

        for(int i=0; i<repeat; i++){
            cin>>xcurrent>>ycurrent;

            if(xcurrent == xlog | ycurrent == ylog)cout<<"divisa\n";
            
            else if(xcurrent>xlog && ycurrent > ylog)cout<<"NE\n";

            else if(xcurrent<xlog && ycurrent > ylog)cout<<"NO\n";

            else if(xcurrent<xlog && ycurrent < ylog)cout<<"SO\n";

            else cout<<"SE\n";

        }


    }

    return 0;
}