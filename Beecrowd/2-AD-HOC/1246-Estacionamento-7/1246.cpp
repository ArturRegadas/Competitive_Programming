#include <bits/stdc++.h>
using namespace std;

int main(){
    int size, cases,placa ,sizeCar, ans;
    char command;
    bool stop, aux;
    while(cin>>size>>cases){
        vector<int> estacionamento(size, 0);
        unordered_map<int, int> position;
        ans=0;
        stop=false;
        for(int r =0;r<cases;r++){
            cin>>command;
            if(command == 'C'){
                scanf("%d%d",&placa, &sizeCar);
                for(int i =0;i<=size-sizeCar;i++){
                    if(estacionamento[i] == 0){
                        aux=true;
                        for(int j = i+1; j<i+sizeCar;j++){
                            if(estacionamento[j]>0){
                                aux=false;
                                break;
                            }
                        }
                        if(aux){
                            estacionamento[i] = sizeCar;
                            ans++;
                            position[placa] = i;
                            break;
                        }
                    }
                    else{
                        i+=estacionamento[i]-1;
                    }
                }
            }
            else{
                scanf("%d", &placa);
                estacionamento[position[placa]] = 0;
                position.erase(placa);
            }

        }
        
        printf("%d\n",ans*10);
    }

    return 0;
}