#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};

char* serialize(struct TreeNode* root) {
    if (root == NULL) {
        return strdup("null");
    }

    char* left = serialize(root->left);
    char* right = serialize(root->right);

    int size = snprintf(NULL, 0, "%d,%s,%s", root->val, left, right);
    char* result = (char*)malloc(size + 1);

    sprintf(result, "%d,%s,%s", root->val, left, right);
    free(left);
    free(right);

    return result;
}
struct TreeNode* deserializeHelper(char** data) {
    if (**data == '\0') return NULL;

    char* token = strsep(data, ",");
    if (strcmp(token, "null") == 0) {
        return NULL;
    }

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = atoi(token);
    node->left = deserializeHelper(data);
    node->right = deserializeHelper(data);

    return node;
}

struct TreeNode* deserialize(char* data) {
    char* dataCopy = strdup(data);
    struct TreeNode* root = deserializeHelper(&dataCopy);
    free(dataCopy);
    return root;
}




