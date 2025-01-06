#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int sldata;

typedef struct slnode
{
    sldata data;
    struct slnode* next;
}slnode;

typedef struct slnode SLN;

void print(SLN*phead){
    SLN*cur=phead;
    while(cur!=NULL){
        printf("%d->",cur->data);
        cur=cur->next;
    }
}

void back(SLN**pphead,sldata i)
{
    slnode*news=(slnode*)malloc(sizeof(slnode));
    news->data=i;
    news->next=NULL;

    if(*pphead==NULL){
        *pphead = news;
    }
    else{
        slnode*tail=*pphead;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=news;
    }
}

void front(SLN**pphead,sldata i){
    slnode*news=(slnode*)malloc(sizeof(slnode));
    news->data=i;
    news->next=NULL;

    news->next=*pphead;
    *pphead=news;  
}

void popfront(SLN**pphead){
    slnode*next=(*pphead)->next;
    free(*pphead);
    *pphead=next;
}

void popback(SLN**pphead){
    if(*pphead==NULL){
        return;
    }
    else if((*pphead)->next==NULL){
        free(*pphead);
        *pphead = NULL;
        return;
    }
    slnode*tail=*pphead;
    slnode*prev=NULL;
    while(tail->next!=NULL){
        prev=tail;
        tail=tail->next;
    }
    free(tail);
    prev->next = NULL;
}

void insert(SLN**pphead,sldata i,slnode*pos){
    if(pos==*pphead){
        front(pphead,i);
        return;
    }
    slnode*prev=*pphead;
    while(prev->next!=pos){
        prev=prev->next;
    }
    slnode*news=(slnode*)malloc(sizeof(slnode));
    news->data=i;
    news->next=NULL;
    prev->next=news;
    news->next=pos;
}

slnode * find(SLN*phead,sldata i){
    slnode *cur=phead;
    while(cur){
        
        if(cur->data==i){
            return cur;
        }
        cur=cur->next;
    }
    return NULL;
}

void delease(slnode**pphead,slnode*pos){
    if(pos==*pphead)
    {
        popfront(pphead);
    }
    else
    {
    slnode*prev=*pphead;
    while(prev->next!=pos){
        prev=prev->next;
    }
    prev->next=pos->next;
    free(pos);
    }
}

void test(){
    slnode* pplist=NULL;
    back(&pplist,2);
    back(&pplist,3);
    back(&pplist,4);
    back(&pplist,5);
    front(&pplist,1);
    front(&pplist,0);
    popback(&pplist);
    popfront(&pplist);   
    slnode*pos=find(pplist,1);
    if(pos){
        insert(&pplist,30,pos);
    }    
    delease(&pplist,pos);
    print(pplist);
}

int main(){
    test();
    printf("NULL\n");
    return 0;
}