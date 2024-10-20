/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {

}

/** Decodes your encoded data to tree. */
struct TreeNode* create(int data){
    struct TreeNode* TemporaryList = malloc(sizeof(struct TreeNode*));
    TemporaryList -> val =data;

}


struct TreeNode* deserialize(char* data) {
    
    
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);