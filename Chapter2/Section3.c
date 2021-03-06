#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct node{//创建链表
    int data;
    struct node *next;
}Node;

typedef struct{//创建队列
    Node *front;
    Node *rear;
    int items;
}Queue;

typedef struct{//创建栈
    int buf[12];
    int top;
}Stack;

void Pushque(int *source,Queue *pq){
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

void Pullque(int *target,Queue *pq){
    *target=pq->front->data;
    Node *pt=pq->front;
    pq->front=pq->front->next;//如果队列清空，front会变成NULL
    free(pt);
    pq->items--;
    if(pq->items==0)//如果队列已空
        pq->rear=NULL;//将尾端设为NULL
}

void Showque(Queue *pq){//打印队列
    Node *pn=pq->front;//创建一个链表指针
    while(pn!=NULL){//当指向的节点不为空
        printf(" %d",pn->data);//打印Item
        pn=pn->next;//将指针移动到下一项
    }
}

void Inique(Queue *pq){
    pq->front=pq->rear=NULL;
    pq->items=0;
}

void Pushsta(int *source,Stack *psta){//压栈
    psta->buf[psta->top]=*source;//将项放入首位
	psta->top++;//移动top指向的位置
}

void Pullsta(int *target,Stack *psta){
    psta->top--;//移动指向的位置
    *target=psta->buf[psta->top];//将项放到目标上
    psta->buf[psta->top]=0;//“释放”这个项
}

void Showsta(Stack *psta){
    int i,n=psta->top;
    for(i=0;i<n;i++)
        printf(" %d",psta->buf[i]);
}

void Inista(Stack *psta){
    memset(psta->buf,0,sizeof(int)*12);
    psta->top=0;
}

void operate(Queue *player,Stack *table,int book[]){
    int temp,i;
    Pullque(&temp,player);//从手牌中拿出一张牌
    if(book[temp]==0){//如果没有重复的牌
        Pushsta(&temp,table);
        book[temp]=1;
    }else{//如果有重复的牌
        Pushque(&temp,player);//把拿出的牌入队
        book[temp]=0;//将标记取消
        do{
            Pullsta(&i,table);//从桌子上拿走牌
            Pushque(&i,player);//把牌放在队尾
            book[i]=0;
        }while(i!=temp);
    }
}

void Win(Queue *player,Stack *table,int mark){
    char s[]="小哼";
    if(mark==2)
        strcpy(s,"小哈");
    printf("%swin\n%s当前的手牌是",s,s);
    Showque(player);
    if(table->top){
        printf("\n桌子上的牌是");
        Showsta(table);
    }else
        puts("\n桌子上已经没牌了");
}

int main(){
    int h1[12]={2,4,1,2,5,6},h2[12]={3,1,3,5,6,4},i,book[10];
    Queue Hum,Ha;
    Stack Table;
    Inique(&Hum);
    Inique(&Ha);
    Inista(&Table);
    memset(book,0,sizeof(int)*10);
    for(i=0;i<6;i++){
        Pushque(h1+i,&Hum);
        Pushque(h2+i,&Ha);
    }
    while(Hum.items&&Ha.items){
        operate(&Hum,&Table,book);
        if(Hum.items==0)
            break;
        operate(&Ha,&Table,book);
    }
    if(Hum.items)
        Win(&Hum,&Table,1);
    else
        Win(&Ha,&Table,2);
    return 0;
}
