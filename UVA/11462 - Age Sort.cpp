#include <bits/stdc++.h>

using namespace std;

int a[2000000];

int main(){

    int n;
    while(scanf("%d",&n) && n){
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        for(int i=0;i<n;i++)
            printf("%d%s",a[i],i==n-1?"\n":" ");
    }
    return 0;
}
