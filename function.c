void mult(int a[],int n,int x){
    int i;
    for(i=0;i<n;i++)
        a[i]*=x;
    for(i=0;i<n;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
}

int isprime(int x){
    if(x<2)
        return 0;
    if(x==2)
        return 1;
    if(x%2==0)
        return 0;
    if(i=0;i*i<=n;i+=2)
        if(x%i==0)
            return 0;
    return 1;
}

char *s_gets(char *st,int n){/* 需要string.h头文件 */
    char *ret_val,*find;
    ret_val=fgets(st,n,stdin);
    if(ret_val==NULL)
        return ret_val;/* 如果获得空指针,则直接返回空指针 */
    find=strchr(st,'\n');/*找到'\n'的位置,并赋给一个指针*/
    if(find)/* 将'\n'替换为'\0' */
        *find='\0';
    else/*将一行剩下的字符全部读取并丢弃*/
        while(getchar()!='\n')
            continue;
    return ret_val;
}

/* 筛选法求素数 */
int *filtrate(int *a,int n){
    int i,j;
    a=malloc(sizeof(int)*n);//获得元素大小的素数
    for(i=0;i<n;i++)
        a[i]=i;
    a[1]=0;/* 1不是素数,去掉这个元素 */
    for(i=2;i*i<=n;i++){
        if(a[i]==0)
            continue;
        for(j=i+1;j<=n;j++)
            if(a[j]&&a[j]%a[i]==0)
                a[j]=0;
    }
    for(i=0,j=0;i<n;i++)
        if(a[i])
            a[j++]=a[i];
    return realloc(a,sizeof(int)*j);
}