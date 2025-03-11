#include <iostream>
#include <string>
using namespace std;
int main() {
    string A;
    long long B, resto = 0;
    cin >> A >> B;
    for (char c : A) {
        resto = (resto * 10 + (c - '0')) % B;
    }
    cout << resto << endl;
    return 0;
}
