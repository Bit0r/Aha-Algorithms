#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool b[3][64]={false};
int n,location[64];

void dfs(int step){
    if(step>n){
        for(int i=1;i<=n;i++)
            printf("%d ",location[i]);
        putchar('\n');
        return;
    }
    int i=step,j;
    for(j=1;j<=n;j++){
        if(b[1][j]==false&&b[2][i-j+n]==false&&b[3][i+j]==false){
            location[step]=j;
            b[1][j]=b[2][i-j+n]=b[3][i+j]=true;
            dfs(step+1);
            b[1][j]=b[2][i-j+n]=b[3][i+j]=false;
        }
    }
}

int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}