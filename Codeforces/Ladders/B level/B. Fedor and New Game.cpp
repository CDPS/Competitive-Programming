#include <bits/stdc++.h>

using namespace std;

int a[1001];

int bits(int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main(){

    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int me;
    for(int i=0;i<m;i++) scanf("%d",a+i);
    scanf("%d",&me);
    int ans=0;
    for(int i=0;i<m;i++){
        int r = me^a[i];
        if(bits(r)<=k)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
