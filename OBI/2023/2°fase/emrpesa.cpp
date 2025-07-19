#include <bits/stdc++.h>
#define uset unordered_set
#define umap unordered_map
#define INF (int)1e9+10
using namespace std;

// key , [pai, salario, filhos]
umap<int, vector<int>> tree;
uset<int> irregular;

int main(){
    int n;
    scanf("%d", &n);
    int mb, ms;
    scanf("%d%d", &mb, &ms);
    tree[-1] = {-1, INF, 1};
    tree[1] = {-1, ms};
    for(int i =1; i<n; i++){
        scanf("%d%d", &mb, &ms);
        //adiciona i+1 ao boss  
        tree[mb].push_back(i+1);
        tree[i+1] = {mb, ms};
        //se salario do i+1 for maior que o salario do pai de i+1
        if(tree[i+1][1] > tree[tree[i+1][0]][1])
            irregular.insert(tree[i+1][0]);
    }
    int c, nb, ns;
    scanf("%d", &c);

    printf("%d\n", irregular.size());
    
    for(int i =0; i<c; i++){
        scanf("%d%d", &nb, &ns);
        tree[nb][1] = ns;
        int pai = tree[nb][0];
        if (pai != -1) {
            bool violacao = false;
            for (int i = 2; i < tree[pai].size(); i++) {
                int filho = tree[pai][i];
                if (tree[filho][1] > tree[pai][1]) {
                    violacao = true;
                    break;
                }
            }
            if (violacao)
                irregular.insert(pai);
            else
                irregular.erase(pai);
        }

        // Atualiza o próprio nb
        bool violacao = false;
        for (int i = 2; i < tree[nb].size(); i++) {
            int filho = tree[nb][i];
            if (tree[filho][1] > tree[nb][1]) {
                violacao = true;
                break;
            }
        }
        if (violacao)
            irregular.insert(nb);
        else
            irregular.erase(nb);
    
        printf("%d\n", irregular.size());
    }


    return 0;
}