#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
}ListNode;

struct ListNode *readlist(){
    int count = 0;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *newlist = (struct ListNode*)malloc(sizeof(struct ListNode));
    while(1){
        struct ListNode *nextlist = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d",&newlist->data);
        if(newlist->data == -1){
            break;
        }        
        
        newlist->next = nextlist;if(count == 0){
            head = newlist;
        }
        newlist = newlist->next;
        count++;
    }
    return head;
}

int main(){

    struct ListNode *L, *Odd;
    L = readlist();
    while(L->next->next){
        printf("%d->",L->data);
        L= L->next;
    }
    printf("%d\n",L->data);
    return 0;

}