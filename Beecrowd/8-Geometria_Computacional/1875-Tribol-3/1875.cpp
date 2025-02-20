#include <bits/stdc++.h>
using namespace std;

string calcS(int points[]){
    if(points[0]== points[1] && points[0]==points[2])return "trempate\n";
    if(points[0]> points[1] && points[0]>points[2])return "red\n";
    if(points[1]> points[0] && points[1]>points[2])return "green\n";
    if(points[2]> points[1] && points[2]>points[0])return "blue\n";
    return "empate\n";
    
}

int main(){
    int repeat;scanf("%d", &repeat);
    char m, s;
    int l;
    for(int r =0;r<repeat;r++){
        int point[3] = {0,0,0};
        scanf("%d",&l);
        for(int i =0;i<l;i++){
            scanf("%c%c",&m, &s);
            if(m=='R'){
                if(s=='G'){
                    point[0]+=2;
                }
                else{
                    point[0]+=1;
                }
            }
            if(m=='G'){
                if(s=='B'){
                    point[1]+=2;
                }
                else{
                    point[1]+=1;
                }
            }
            if(m=='B'){
                if(s=='R'){
                    point[2]+=2;
                }
                else{
                    point[2]+=1;
                }
            }
        }

        printf("%s", calcS(point));

    }


    return 0;
}