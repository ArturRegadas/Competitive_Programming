#include <bits/stdc++.h>
using namespace std;

class BigInt {
public:
    string value;  

    BigInt(): value("0") {}
    BigInt(const string& s): value(s) { 
        reverse(value.begin(), value.end()); 
    }

    BigInt operator+(const BigInt& other) const {
        string result;
        int carry = 0;
        int n = max(value.size(), other.value.size());

        for (int i = 0; i < n; ++i) {
            int digit1 = (i < (int)value.size()) ? value[i] - '0' : 0;
            int digit2 = (i < (int)other.value.size()) ? other.value[i] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            sum %= 10;
            result.push_back(sum + '0');
        }

        if (carry) {
            result.push_back(carry + '0');
        }

        return BigInt(string(result.rbegin(), result.rend()));
    }

    friend ostream& operator<<(ostream& os, const BigInt& b) {
        string out = b.value;
        reverse(out.begin(), out.end());
        os << out;
        return os;
    }
};
BigInt tribonacci(unsigned long long n) {
    if (n == 0) return BigInt("1");
    if (n == 1) return BigInt("1");
    if (n == 2) return BigInt("2");
    if (n == 3) return BigInt("4");

    vector<BigInt> dp(n+1);
    dp[0] = BigInt("1");
    dp[1] = BigInt("1");
    dp[2] = BigInt("2");
    dp[3] = BigInt("4");

    for (unsigned long long i = 4; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main() {
    unsigned long long n;
    cin >> n;

    cout << tribonacci(n) << "\n";

    return 0;
}
