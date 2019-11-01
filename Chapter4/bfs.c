#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int q[64][3],map[64][64],m,n,start[2],end[2];

void input() {
	int i,j;
	for(i=1; i<=m; i++)
		for(j=1; j<=n; j++)
			scanf("%d",&map[i][j]);
}

int bfs() {
	int front,rear,k,next_i,next_j;
	int next[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
	bool book[64][64];
	memset(book,0,sizeof(bool)*64*64);
	q[0][0]=start[0];
	q[0][1]=start[1];
	q[0][2]=-1;
	for(front=rear=0; front<=rear; front++) {
		for(k=0; k<4; k++) {
			next_i=q[front][0]+next[k][0];
			next_j=q[front][1]+next[k][1];
			if(next_i<=m&&next_i>0&&next_j>0&&next_j<=n\
			&&map[next_i][next_j]==0&&!book[next_i][next_j]) {
				rear++;
				q[rear][0]=next_i;
				q[rear][1]=next_j;
				q[rear][3]=front;
				book[next_i][next_j]=true;
			}
			if(q[rear][0]==end[0]&&q[rear][1])
				return rear;
		}
	}
	return -1;
}

void output(int rear){
	int stack[64][2],pre,top;
	for(top=0,pre=rear;q[pre][2]!=-1;top++,pre=q[pre][2]){
		stack[top][0]=q[pre][0];
		stack[top][1]=q[pre][1];
	}
	stack[top][0]=start[0];
	stack[top][1]=start[1];
	for(;top>0;top--)
		printf("(%d,%d)->",stack[top][0],stack[top][1]);
	printf("(%d,%d)",end[0],end[1]);
}

int main() {
	scanf("%d%d",&m,&n);
	input();
	scanf("%d%d%d%d",start,start+1,end,end+1);
	output(bfs());
	return 0;
}
