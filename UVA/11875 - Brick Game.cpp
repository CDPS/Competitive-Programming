#include <bits/stdc++.h>

using namespace std;

int a[10];

int main(){

    int t,caseno=1,n;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);

        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        printf("Case %d: %d\n",caseno++,a[n/2]);
    }
    return 0;
}
