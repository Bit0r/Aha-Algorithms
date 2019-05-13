#include<stdio.h>

void quicksort(int a[],int left,int right){
    if(left>right)
        return;
    int i=left,j=right,temp;
    while (i!=j){
        while(a[j]>=a[left]&&i!=j)
            j--;
        while(a[i]<=a[left]&&i!=j)
            i++;
        if(i!=j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i];
    a[i]=a[left];
    a[left]=temp;
    quicksort(a,i+1,right);
    quicksort(a,left,i-1);
}

int dedup(int a[],int n){
    int i,j;
    for(i=j=1;i<n;i++)
        if(a[i]!=a[i-1])
            a[j++]=a[i];
    return j;
}

int main(){
    int i,n,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    quicksort(a,0,n-1);
    n=dedup(a,n);
    printf("%d\n",n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
