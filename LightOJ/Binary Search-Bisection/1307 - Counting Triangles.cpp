#include <bits/stdc++.h>

using namespace std;

long long a[2000];

int n;

int binarySearch(long long x){
    int l = 0, h = n-1;
    while(l< h){
        int  m = l + ((h-l+1)/2 );
        if( a[m] >= x)
             h = m-1;
        else l = m;
    }
    return l;
}

int main(){

    int t,caseno=1;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);

        for(int i=0;i<n;i++) scanf("%lld",a+i);
        sort(a,a+n);

        int ans =0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int idx = binarySearch(a[i]+a[j]);
                ans = ans +  max(0,(idx-j));
            }
        }
        printf("Case %d: %d\n",caseno++,ans);
    }
    return 0;
}
