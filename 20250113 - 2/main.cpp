#include <stdio.h>
#include <string.h>
#define N 100
int convert(char a[],int x[]);
int add(int x[],int len1,int y[],int len2,int z[]);

int main()
{
    char a[N],b[N];
    int m[N/4+1],n[N/4+1],s[N/4+1],len1,len2,len3,i;
    scanf("%s%s",a,b);
    len1=convert(a,m);
    len2=convert(b,n);
    len3=add(m,len1,n,len2,s);
    printf("%d,",s[len3-1]);
    for(i=len3-2;i>0;i--)
        printf("%04d,",s[i]);
    printf("%04d",s[0]);
    return 0;
}
int convert(char a[],int x[]){
    int num = 0;
    int l = strlen(a);
    int cnt = 0;
    int k = 1;
    for(int i = l - 1 ; i >= 0 ; i -- ){
        num = num + (a[i] - '0') * k;
        k *= 10;
        if((l - i) % 4 == 0 || i == 0){
            x[cnt++] = num;
            k = 1;
            num = 0;
        }
    }
    return cnt;
}
int add(int x[],int len1,int y[],int len2,int z[]){
    int l = len1 > len2 ? len1 : len2;
    int p = 0;
    for(int i = 0 ; i <= l + 1 ; i ++ )z[i] = 0;
    for(int i = 0 ; i < l ; i ++ ){
        if(i < len1)z[i] += x[i];
        if(i < len2)z[i] += y[i];
    }

    for(int i = 0 ; i < l ; i ++ ){
        if(z[i] > 10000){
            z[i + 1] += z[i] / 10000;
            z[i] %= 10000;
            if(i == l - 1) l ++ ;
        }
    }
    printf("%d\n", l);
    return l - 4;
}