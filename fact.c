#include<stdio.h>
#define K 1024

void mult(int a[],int n,int x){
    int i;
    for(i=0;i<n;i++)
        a[i]*=x;
    for(i=0;i<n;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
}

int main(){
    int a[K],i,n;
    scanf("%d",&n);
    a[0]=1;
    for(i=1;i<K;i++)
        a[i]=0;
    for(i=1;i<=n;i++)
        mult(a,K,i);
    i=K-1;
    while(a[i]==0)
        i--;
    for(;i>=0;i--)
        printf("%d",a[i]);
    return 0;
}