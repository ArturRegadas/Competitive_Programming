#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        string p1, p2, ans;
        cin >> p1 >> p2;
        
        int min_len = min(p1.size(), p2.size());

        for (int i = 0; i < min_len; i++) {
            ans += p1[i];
            ans += p2[i];
        }
        
        ans += (p1.size() > p2.size()) ? p1.substr(min_len) : p2.substr(min_len);

        cout << ans << endl;
    }

    return 0;
}
