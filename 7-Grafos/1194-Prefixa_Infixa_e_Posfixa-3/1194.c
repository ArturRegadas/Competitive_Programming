#include <stdio.h>
#include <string.h>

int findIndex(char str[], char ch, int size) {
    for(int i = 0; i < size; i++) {
        if (str[i] == ch) {
            return i;
        }
    }
    return -1;
}

void infixToPostfix(char prefix[], char infix[], int size, char result[]) {
    // Assuming the prefix expression is valid and root is always the first element
    char root = prefix[0];
    int rootIndex = findIndex(infix, root, size);
    
    if (rootIndex == -1) {
        printf("Error: root not found in infix\n");
        return;
    }

    int m = 0;

    // Process left subtree
    for (int i = 0; i < rootIndex; i++) {
        result[m++] = infix[i];
    }
    
    // Process right subtree
    for (int i = rootIndex + 1; i < size; i++) {
        result[m++] = infix[i];
    }
    
    // Add root to result
    result[m++] = root;
    result[m] = '\0'; // Null-terminate the result string
}

int main() {
    int repeat, size;
    char prefix[53], infix[53], result[53];

    scanf("%d", &repeat);

    for(int r = 0; r < repeat; r++) {
        scanf("%d", &size);
        scanf(" %s", prefix);
        scanf(" %s", infix);

        infixToPostfix(prefix, infix, size, result);
        printf("%s\n", result);
    }

    return 0;
}
