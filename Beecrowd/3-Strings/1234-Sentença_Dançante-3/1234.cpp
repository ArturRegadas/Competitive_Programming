#include <bits/stdc++.h>
using namespace std;

int main() {
    char input[55];
    while (fgets(input, sizeof(input), stdin)) {
        int size = strlen(input);
        int axu = 0;

        for (int i = 0; i < size; i++) {
            if (input[i] == ' ') {
                printf(" ");
                continue;
            }

            axu++; 
            
            if (axu % 2 == 1) {
                if (isupper(input[i])) {
                    printf("%c", input[i]);  
                } else {
                    printf("%c", toupper(input[i])); 
                }
            } else {
                if (islower(input[i])) {
                    printf("%c", input[i]);  
                } else {
                    printf("%c", tolower(input[i]));
                }
            }
        }
    }

    return 0;
}
