#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

int main(){

     int max;
     ListNode*head = (ListNode*)malloc(sizeof(ListNode)); 
     ListNode*newlist = (ListNode*) malloc(sizeof(ListNode));
     printf("please add listnumber:");
     scanf("%d",&max);
     
     for(int i = 0;i < max;i++){
        ListNode*nextlist = (ListNode*)malloc(sizeof(ListNode));//作用是一直为链表动态分配新的结构体
        scanf("%d",&newlist->data);
        if(i==0){
            head = newlist;
        }        
        newlist->next = nextlist;
        newlist = newlist->next;
     }

    while(head->next->next){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("%d\n",head->data);

}