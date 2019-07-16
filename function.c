//大数乘法
void mult(int a[],int n,int x){
    int i;
    for(i=0;i<n;i++)
        a[i]*=x;
    for(i=0;i<n;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
}

//检测素数
int isprime(int x){
    if(x<2)
        return 0;
    if(x==2)
        return 1;
    if(x%2==0)
        return 0;
    if(int i=0;i*i<=n;i+=2)
        if(x%i==0)
            return 0;
    return 1;
}

//自定义的gets函数
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
long *prime(long n){
    long i,j,*a;
    a=malloc(sizeof(long)*n);
    for(i=0;i<=n;i++)
        a[i]=i;
    a[1]=0;
    for(i=2;i*i<=n;i++){
        if(a[i]==0)
            continue;
        for(j=i*i;j<=n;j++)
            if(a[j]&&a[j]%a[i]==0)
                a[j]=0;
    }
    for(i=j=0;i<=n;i++)
        if(a[i])
            a[j++]=a[i];
    a[j]=0;
    return a;
}

//大数阶乘
int factorial(int n){
	int i, j, m = 0, w,a[10000],c;

	a[0] = 1;
	for (i = 1; i <= n; i++){
		c = 0;
		for (j = 0; j <= m; j++){
			a[j] = a[j] * i + c;
			c = a[j] / 10000;
			a[j] = a[j] % 10000;
		}
		if (c > 0){
			m++;
			a[m] = c;
		}
	}

	w = m * 4 + log10(a[m]) + 1;
	printf("\n%d", a[m]);
	for (i = m - 1; i >= 0; i--)
		printf("%4.4d", a[i]);
	return w;
}


//字符串反转
char *mystrrev(char *str){
    char temp;
    int i,n;
    n=strlen(str);
    for(i=0;i<n/2;i++){
        temp=str[i];
        str[i]=str[n-1-i];
        str[n-1-i]=temp;
    }
    return str;	
}

//数组前移
void arrahead(int arr[],int n,int x){
	int *temp,i;
	temp=(int*)malloc(n*sizeof(int));
	x%=n;
	for(i=0;i<n-x;i++)
		temp[i]=arr[i+x];
	for(i=0;i<x;i++)
		temp[i+n-x]=arr[i];
	memcpy(arr,temp,n*sizeof(int));
	free(temp);
}

//数组后移
void arrback(int arr[],int n,int x){
	int *temp,i;
	temp=(int*)malloc(n*sizeof(int));
	x%=n;
	for(i=0;i<n-x;i++)
		temp[i+x]=arr[i];
	for(i=0;i<x;i++)
		temp[i]=arr[i+n-x];
	memcpy(arr,temp,n*sizeof(int));
	free(temp);
}
