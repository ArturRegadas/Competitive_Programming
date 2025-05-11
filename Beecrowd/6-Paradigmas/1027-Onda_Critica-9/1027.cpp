#include <bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
};

point createPoint(int x, int y){
    point a;
    a.x = x;
    a.y = y;
    return a;
}

bool compare(point a, point b){
    return a.x < b.x;
}

int main(){
    int n, aux, auy;
    while(scanf("%d", &n)!=EOF){
        vector<point> points(n);
        for(int i =0; i<n;i++)scanf("%d%d", &points[i].x, &points[i].y);
        sort(points.begin(), points.end(), compare);
        vector<int>dpT(n, 0);
        vector<int>dpB(n, 0);
        dpT[0] = 1;dpB[0]=1;
        for(int i =1; i<n;i++){
            int auT = 1, auB = 1;
            for(int j =0; j<n;j++){
                if(points[i].x > points[j].x && points[i].y == points[j].y+2)
                    auT=max(auT, dpB[j]+1);

                if(points[i].x > points[j].x && points[i].y == points[j].y-2)
                    auB = max(auB, dpT[j]+1);
            }
            dpT[i] = auT;
            dpB[i] = auB;
        }

        int ans = 1;
        for(int i =0;i<n;i++){
            ans=max(ans, dpT[i]);
            ans=max(ans, dpB[i]);
        }
        printf("%d\n", ans);
        
    }

    return 0;
}