#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n,m,next[][2]={{0,1},{1,0},{0,-1},{-1,0}},x,y,p,q;
typedef struct{
	int x;
	int y;
	int s;
}Item;
typedef struct node{
	Item data;
	struct node *next;
}Node;
typedef struct{
	Node *front;
	Node *rear;
	int items;
}Que;

void input(int [n][m]);
void dfs(int [n][m],int [n][m],int [],int);

int main(){
	Item start;
	scanf("%d%d",&n,&m);
	int map[n][m],book[n][m];
	input(map);
	scanf("%d%d%d%d",&start.x,&start.y,&p,&q);
	start.x--,start.y--,p--,q--;
	start.s=0;
	memset(book,0,sizeof(int)*n*m);
	book[start.x][start.y]=1;
	queadd(&hum,&start);
	bfs(map,book);
	if(flag)
	return 0;
}

void input(int map[n][m]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&map[i][j]);
}

int bfs(int map[n][m],int book[n][m]){
	bool flag=0;
	int i;
	Que hum={NULL,NULL,0};
	Item temp,place;
	while(hum->front!=NULL){
		quedel(&hum,&place);
		for(i=0;i<4;i++){
			temp.x=place.x+next[i][0];
			temp.y=place.y+next[i][1];
			if(temp.x>=0&&temp.x<n&&temp.y>=0&&temp.y<m\
			&&map[temp.x][temp.y]==0&&book[temp.x][temp.y]==0){
				book[temp.x][temp.y]=1;
				temp.s=place.s+1;
				queadd(&hum,temp);
			}
			if(temp.x==p&&temp.y==q){
				flag=1;
				break;
			}
		}
		if(flag==1)
			break;
	}
	if(flag)
		return temp.s;
	else
		return -1;
}

void queadd(Que *pque,Item *pitem){
	Node *pnew=malloc(sizeof(Node));
	pnew->next=NULL;
	pnew->next=*pitem;
	if(pque==NULL){
		pque->front=pque->rear=pnew;
		items=1;
	}else{
		pque->rear->next=pnew;
		pque->rear=pnew;
		pque->items++;
	}
}

void quedel(Que *pque,Item *pitem){
	Node temp=pque->front;
	*pitem=pque->front.data;
	pque->front=pque->front->next;
	pque->items--;
	if(pque->front==NULL)
		rear=NULL;
	free(temp);
}
