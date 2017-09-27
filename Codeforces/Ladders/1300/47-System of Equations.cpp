#include <bits/stdc++.h>

using namespace std;

int main(){
    long n,m;
    scanf("%ld %ld",&n,&m);

    long res=0;
    for(long i=0;i<=n;i++)
        for(long j=0;j<=m;j++)
            if(  (i*i)+j ==n && (j*j)+i==m )
              res++;

    printf("%ld\n",res);
    return 0;
}
