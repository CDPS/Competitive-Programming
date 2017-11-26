#include <bits/stdc++.h>

using namespace std;

long long a[51];

int main(){

    int n;

    a[1]=1;a[2]=2;
    for(int i=3;i<=50;i++)
        a[i] = a[i-1] + a[i-2];

    while(scanf("%d",&n) && n ){
        printf("%lld\n",a[n]);
    }

    return 0;
}
