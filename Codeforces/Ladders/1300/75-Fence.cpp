#include <bits/stdc++.h>

using namespace std;

int a[1500001],n,k;

int main(){
    scanf("%d %d",&n,&k);

    a[0]=0;
    for(int i=1;i<=n;i++)
     scanf("%d",a+i), a[i]+=a[i-1];

    int mini=30000000,ii;

    for(int i=1;i<=n-k+1;i++){
        int r = a[i+k-1]-a[i-1];
        if(r < mini)
            mini = r, ii=i;
    }

    printf("%d\n",ii);
    return 0;
}
