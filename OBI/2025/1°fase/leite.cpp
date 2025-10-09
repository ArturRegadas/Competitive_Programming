#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int leite = C - D;
    if (A <= leite && leite <= B)
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
