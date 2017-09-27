#include <bits/stdc++.h>

using namespace std;

int a [100000];

int main(){

    int n, k;
    scanf("%d %d",&n,&k);

    for(int i=0;i<n;i++)
        scanf("%d", a+i);

    int c= a[n-1], cc=0;

    int i= n-1;
    while(i>=0 ){
        if( a[i]!=c )break;
        cc++;
        i--;
    }

    if(k>=(n-cc)+1){
        printf("%d\n",n-cc);
    }else{
        printf("-1\n");
    }
    return 0;
}
