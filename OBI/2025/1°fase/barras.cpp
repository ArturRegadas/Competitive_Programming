#include <bits/stdc++.h>

using namespace std;

int max(vector<int> nu){
    int maxi = -1;
    for(int i : nu){
        if (i > maxi)
            maxi = i;
    }
    return maxi;
}

int main(){

    int n, x;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i<n;i++){
        cin>>nums[i];
    }
    int maxi = max(nums);

    vector<vector<int>> matriz(maxi, vector<int>(n, 0));
    int c =0;
    for(int i : nums){
        for(int j = maxi-1; j>=maxi-i; j--){
            matriz[j][c] = 1;
        }
        c++;
    }

    for(int i =0; i<maxi; i++){
        for(int j = 0; j<n-1; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("%d\n", matriz[i][n-1]);
    }



    return 0;
}