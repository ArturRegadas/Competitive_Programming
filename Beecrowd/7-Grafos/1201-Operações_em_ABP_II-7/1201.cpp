#include <bits/stdc++.h>
using namespace std;


struct node{
    int* val;
    node* left;
    node* right;
    node* parent;
    
    node() {
        val = new int;
        *val = -1;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

};
node* nullNode() {
    node* nullnode = new node();  
    *nullnode->val = -1;
    return nullnode;
}

node* CreateNode(node* parent, int data) {
    node* newNode = new node();  
    *newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent;
    return newNode;
}
void InsertNode(node* no, int data){
    if(*no->val>=data){
        if(no->left==NULL)no->left = CreateNode(no, data);
        else InsertNode(no->left, data);
        return;
    }
    if(no->right==NULL)no->right = CreateNode(no, data);
    else InsertNode(no->right, data);
    return;
    
}

node* InTree(node* no, int data){
    if (*no->val==-1)return nullNode();
    if(*no->val == data)return no;
    if(data<*no->val){
        if(no->left==NULL)return nullNode();
        return InTree(no->left, data);
    }
    if(no->right==NULL)return nullNode();
    return InTree(no->right, data);
    
}
node* GetMaxNode(node* no){
    if(no->right==NULL)return no;
    return GetMaxNode(no->right);
}

void RemoveOfTree(node* &no, int data) {
    node* position = InTree(no, data);
    if (!position || *position->val == -1) return;

    node* parent = position->parent;

    if (!position->left && !position->right) { 
        if (position == no) {
            no = nullNode();
        }
        else if (data < *parent->val) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }
        return;
    }

    if (position->left && !position->right) { 
        if (position == no) {
            no = position->left;
            no->parent = NULL;
        }
        else if (data < *parent->val) {
            parent->left = position->left;
        }
        else {
            parent->right = position->left;
        }
        position->left->parent = parent;
        return;
    }

    if (!position->left && position->right) { 
        if (position == no) {
            no = position->right;
            no->parent = NULL;
        }
        else if(data < *parent->val) {
            parent->left = position->right;
        }
        else {
            parent->right = position->right;
        }
        position->right->parent = parent;
        return;
    }

    node* maxNode = GetMaxNode(position->left);
    swap(*position->val, *maxNode->val);

    node* maxParent = maxNode->parent;
    if (maxParent->right == maxNode) {
        maxParent->right = maxNode->left;
        if(maxNode->right)maxNode->right->parent = maxParent;
    }
    else{
        maxParent->left = maxNode->left;
    }
    
    if (maxNode->left)maxNode->left->parent = maxParent;
    
}




void Prefix(node* no, vector<int>& vec){
    if (no == NULL || *no->val == -1) return;
    vec.push_back(*no->val);
    Prefix(no->left, vec);
    Prefix(no->right, vec);
}
void Infix(node* no, vector<int>& vec) {
    if (no == NULL || *no->val == -1) return;
    Infix(no->left, vec);
    vec.push_back(*no->val);
    Infix(no->right, vec);  
}
void Posfix(node* no, vector<int>& vec){
    if (no == NULL || *no->val == -1) return;
    if(no->left)Posfix(no->left,vec);
    if(no->right)Posfix(no->right, vec);
    vec.push_back(*no->val);
}


void printList(vector<int> l ){
    for(int i =0;i<l.size()-1;i++)printf("%d ", l[i]);
    printf("%d\n", l.back());
}


int main(){
    string command;
    int val;
    node* root= nullNode();
    while(cin>>command){
        if(command == "I"){
            cin>>val;
            if(*root->val==-1){
                *root->val=val;
            }
            else{
                InsertNode(root, val);
            }
        }
        else if(command ==  "R"){
            scanf("%d", &val);
            RemoveOfTree(root, val);
        }
        
        else if(command == "P"){
            scanf("%d", &val);
            if(*InTree(root, val)->val==-1){
                printf("%d nao existe\n", val);
            }
            else{
                printf("%d existe\n", val);
            }
        }
        
        else if(command == "INFIXA"){
            vector<int>Inf;
            Infix(root, Inf);
            printList(Inf);
        }
        
        else if(command == "PREFIXA"){
            vector<int>Pre;
            Prefix(root, Pre);
            printList(Pre);
        }
        
        else if(command == "POSFIXA"){
            vector<int>Pos;
            Posfix(root, Pos);
            printList(Pos);
        }
        
        
    }


    return 0;
}