#include<stdio.h>
int upsum(int,int,char [*][*],int,int);
int lowsum(int,int,char [*][*],int,int);
int leftsum(int,int,char [*][*],int,int);
int rightsum(int,int,char [*][*],int,int);
void input(int,int,char [*][*]);

int main() {
	int n,m,i,j,max=0,s,p,q;
	scanf("%d%d",&n,&m);
	char map[n][m];
	input(n,m,map);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(map[i][j]!='.')
				continue;
			s=upsum(n,m,map,i,j)+lowsum(n,m,map,i,j)\
			+leftsum(n,m,map,i,j)+rightsum(n,m,map,i,j);
			if(max<s){
				max=s;
				p=i;
				q=j;
			}
		}
	}
	printf("将炸弹放置在(%d,%d)处,最多可以消灭%d个敌人",p,q,max);
	return 0;
}

void input(int n,int m,char arr[n][m]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf(" %c",&arr[i][j]);
}

int upsum(int n,int m,char map[n][m],int x,int y){
	int i,s=0;
	for(i=x;i>=0&&map[i][y]!='#';i--)
		if(map[i][y]=='G')
			s++;
	return s;
}

int lowsum(int n,int m,char map[n][m],int x,int y){
	int i,s=0;
	for(i=x;i<n&&map[i][y]!='#';i++)
		if(map[i][y]=='G')
			s++;
	return s;
}

int leftsum(int n,int m,char map[n][m],int x,int y){
	int j,s=0;
	for(j=y;j>=0&&map[x][j]!='#';j--)
		if(map[x][j]=='G')
			s++;
	return s;
}

int rightsum(int n,int m,char map[n][m],int x,int y){
	int j,s=0;
	for(j=y;j<n&&map[x][j]!='#';j++)
		if(map[x][j]=='G')
			s++;
	return s;
}
