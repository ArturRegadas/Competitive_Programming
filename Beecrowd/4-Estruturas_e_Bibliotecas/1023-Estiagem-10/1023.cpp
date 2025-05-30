#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, size, water;
    double totalW, totalP;
    int c =1;
    bool first = true;
    while(1){
        scanf("%d", &cases);
        if(cases==0)return 0;
        if(!first)printf("\n");
        first = false;
        map<int, int> city;
        totalW = 0;
        totalP= 0;
        for(int i=0;i<cases;i++){
            scanf("%d%d", &size, &water);
            totalP += size;
            totalW +=water;

            if(city.find(water/size) != city.end())city[water/size] += size;  
            else city[water/size] = size;  

        }
        printf("Cidade# %d:\n", c);
        for(const auto& [key, value] : city){
            printf("%d-%d ", value, key);
        }
        printf("Consumo medio: %.2lf m3.\n", floor((totalW/totalP)*100)/100);
        c++;
    }
}