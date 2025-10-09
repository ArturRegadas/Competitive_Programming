#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];


    long long c0 = 0;
    vector<vector<int>> b0 = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int want = (i + j) % 2;
            if (b0[i][j] % 2 != want) {
                b0[i][j]++;
                c0++;
            }
        }
    }

    long long c1 = 0;
    vector<vector<int>> b1 = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int want = (i + j + 1) % 2;
            if (b1[i][j] % 2 != want) {
                b1[i][j]++;
                c1++;
            }
        }
    }

    if (c0 <= c1) {
        cout << c0 << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << b0[i][j] << (j+1==m ? '\n' : ' ');
            }
        }
    } else {
        cout << c1 << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << b1[i][j] << (j+1==m ? '\n' : ' ');
            }
        }
    }

    return 0;
}
