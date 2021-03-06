#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    char data;
    struct node *next;
}Node;

typedef struct{
    Node *front;
    Node *rear;
    int items;
}Queue;

void Pushque(char *source,Queue *pq){
    Node *pnew;
    pnew=malloc(sizeof(Node));
    pnew->data=*source;
    pnew->next=NULL;
    if(pq->items==0)//如果队列为空
        pq->front=pnew;//项位于队列首端
    else
        pq->rear->next=pnew;//链接到队列链表
    pq->rear=pnew;//记录队列尾端
    pq->items++;//队列项数加一
}

void Pullque(char *target,Queue *pq){
    *target=pq->front->data;
    Node *pt=pq->front;
    pq->front=pq->front->next;//如果队列清空，front会变成NULL
    free(pt);
    pq->items--;
    if(pq->items==0)//如果队列已空
        pq->rear=NULL;//将尾端设为NULL
}

int main(){
    char str[]="631758924",*pch=str,temp;
    Queue qq={NULL,NULL,0};
    while(*pch){
        Pushque(pch,&qq);
        pch++;
    }
    pch=str;
    while(qq.items>1){
        Pullque(pch,&qq);
        Pullque(&temp,&qq);
        Pushque(&temp,&qq);
        pch++;
    }
    *pch++=temp;
    *pch='\0';
    puts(str);
    return 0;
}
