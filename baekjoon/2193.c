#include <stdio.h>
int main (){
    int in =0;
    scanf("%d",&in);
    long long a[92] = {0,1,0,};
    for(int i=2;i<=in;i++){
        a[i] = a[i-1]+a[i-2];
    }
    printf("%lld",a[in]);
}