#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Multiplica duas matrizes 3x3 com módulo b
vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B, ll b) {
    vector<vector<ll>> C(3, vector<ll>(3, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % b;
            }
        }
    }
    return C;
}

// Exponenciação de matriz rápida
vector<vector<ll>> matrixExpo(vector<vector<ll>> base, ll exp, ll b) {
    vector<vector<ll>> res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}; // Matriz identidade 3x3
    while (exp > 0) {
        if (exp % 2) res = multiply(res, base, b);
        base = multiply(base, base, b);
        exp /= 2;
    }
    return res;
}

// Calcula calls(n) % b usando exponenciação de matriz
ll calls(ll n, ll b) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    
    vector<vector<ll>> base = {{1, 1, 1}, {1, 0, 0}, {0, 0, 1}}; // Matriz de transição
    vector<vector<ll>> result = matrixExpo(base, n - 1, b);
    
    return (result[0][0] + result[0][1] + result[0][2]) % b;
}

int main() {
    ll n, b;
    int caso = 1;

    while (true) {
        scanf("%lld %lld", &n, &b);
        if (n == 0 && b == 0) break;
        
        printf("Case %d: %lld %lld %lld\n", caso++, n, b, calls(n, b));
    }

    return 0;
}
