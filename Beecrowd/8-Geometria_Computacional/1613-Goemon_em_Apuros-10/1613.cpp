
#include <bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;
};

struct line{
    long double m;
    long double b;
    bool vertical;
};

point constPoint(int a, int b){
    point z;
    z.x = a;
    z.y = b;
    return z;
}

line constLine(point a, point b){
    line z;
    z.vertical = false;
    if (a.x == b.x) z.vertical = true;
    
    z.m = (long double)(b.y-a.y)/(b.x-a.x);
    z.b = a.y - z.m * a.x;
    return z;

}

long double calcFunc(line a, point b){

    return (long double)a.m*b.x+a.b;

}

bool inProtect(point a, pair<line, line> wall){
    line lineF = wall.first;
    line lineS = wall.second;

    if(calcFunc(lineF, a)<a.y && calcFunc(lineS, a)>a.y){
        return true;
    }

    return false;
    
}


int binaryS(vector<pair<int,int>> walls, long double targ, int size){
    int l = 0;
    int r = size;
    int m;
    int response = 0;
    while(l<=r){
        m = (r+l)/2 ;
        if(walls[m].first < targ){
            response = m;
            l = m+1;
        }
        else{
            r = m-1;
        }

    }
    return response;

}





int main(){

    int repeat, aux, auy, qtWalls, qtPoints;
    cin>>repeat;
    for(int r =0; r<repeat; r++){
        cin>>aux>>auy;
        point epicenter = constPoint(aux, auy);
        
        cin>>qtWalls;
        vector<pair<int, int>> walls(qtWalls);
        

        for(int i =0; i<qtWalls; i++){
            cin>>aux>>auy;
            walls[i] = {aux, auy};
        }

        cin>>qtPoints;
        vector<point> Tpoints(qtPoints);
        vector<line> lines(qtPoints);
        for(int i =0; i<qtPoints; i++){
            cin>>aux>>auy;
            Tpoints[i] = constPoint(aux, auy);
            lines[i] = constLine(epicenter, Tpoints[i]);
        }

        int response = 0;
        long double b;
        sort(walls.begin(), walls.end());

        int maxMin;
        //if(r!=4)continue;
        //cout<<qtWalls<<" qtWalls\n";
        for(int i =0; i<qtPoints; i++){
            b = calcFunc(lines[i], {0,0});
            maxMin = binaryS(walls, b, qtWalls-1);
            //cout<<b<<" B\n";
            //cout<<walls[maxMin].first<<" "<<walls[maxMin].second<<" wall\n";
            //cout<<maxMin<<" MaxMin\n";
            if(walls[maxMin].first<b &&walls[maxMin].second > b){
                //cout<<b<<" passou\n";
                response++;
            }

        }
        cout<<response<<"\n";
              //cout<<response<<"\n";
            
        /*
        if(r==4){
            cout<<"( "<<epicenter.x<<", "<<epicenter.y<<" )epicenter\n";
            cout<<"walls: \n";
            for(pair<int, int> l : walls){
                cout<<"{ "<< l.first<<", "<<l.second<<" }\n";
            }
            cout<<"\npoints: \n";
            for(point a : Tpoints){
                cout<<"( "<<a.x<<", "<<a.y<<" )\n";
            }
        }
        */
        
    }

    return 0;
}