#include <bits/stdc++.h>
using namespace std;

int main() {
        int n;
        scanf("%d", &n);
        vector<int> students(n);
        for(int i =0; i<n; i++)
            scanf("%d", &students[i]);
        
        int p = students.back();
        int current, taller = -1;
        int ans = 0;
        for(int i = n-1; i>=0; i--){
            current = students[i];
            if(current > taller){
                taller = current;
                ans ++;
            }
        }
        printf("%d\n", n-ans);

}
