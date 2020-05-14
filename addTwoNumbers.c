#include<stdio.h> 
#include<stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* helper(struct ListNode* l1, struct ListNode* l2, int carry) { 
    if (!l1 && !l2) {
        struct ListNode *lastNode = NULL;
        if (carry){
            lastNode = (struct ListNode*)calloc(1, sizeof(struct ListNode));
            lastNode->val = carry; 
        }
            
        return lastNode;
    }
    else {
        int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        struct ListNode *newNode = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        newNode->val = val % 10;
        newNode->next = helper(l1 ? l1->next : NULL, l2 ? l2->next : NULL, val / 10);
        return newNode;
    }
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){    
    return (helper(l1, l2, 0));
}  
