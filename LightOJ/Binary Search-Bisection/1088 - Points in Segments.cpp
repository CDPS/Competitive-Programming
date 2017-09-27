#include <bits/stdc++.h>

using namespace std;

long a [100002],ql,qh;

int n,q;

int upperBound(long x){
    int l = 0, h=n+1;
    while(l<h){
        int m = l +( (h-l)/2);
        if(a[m]>=x) h = m;
        else l = m+1;
    }
    return l;
}

int lowerBound(long x){
    int l=0, h = n+1;
    while(l<h){
        int m = l + ( (h-l+1)/2 );
        if( a[m] > x ) h = m-1;
        else l = m;
    }
    return l;
}

int main(){

    int t,caseno=1;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&q);
        a[0]=-1;
        for(int i=0;i<n;i++) scanf("%ld",a+i+1);
        a[n+1] =100000001;

        printf("Case %d:\n",caseno++);
        while(q--){
            scanf("%ld %ld",&ql,&qh);

            int lr = upperBound(ql);
            int hr = lowerBound(qh);

            printf("%d\n",hr-lr+1);
        }
    }
    return 0;
}
