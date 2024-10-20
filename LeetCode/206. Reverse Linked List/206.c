//Definition for singly-linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* RootNodeNewList = NULL;
    struct ListNode* prox;
    while(head){
        prox = head -> next;
        head -> next = RootNodeNewList;
        RootNodeNewList = head;
        head = prox;
    }
    return RootNodeNewList;
}