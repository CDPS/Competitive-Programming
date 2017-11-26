#include <bits/stdc++.h>

using namespace std;

const int inf = 200000000;
int memo[920];

int a[20][2], b[20][2];

int main(){

    int t;
    scanf("%d",&t);

    int n,k;

    while(t--){
        scanf("%d %d",&n,&k);

        for(int i=0;i<n/2;i++)
            scanf("%d %d",a[i][0],a[i][1]);
        for(int i=n/2;i<n;i++)
            scanf("%d %d",a[i][0],a[i][1]);

        int res = dp(k);
    }
    return 0;
}
