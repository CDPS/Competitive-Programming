#include <bits/stdc++.h>

using namespace std;

long long a[50000],qi;
int n,q;

int upperBound(long long x){

    int l = 0, h = n-1,m;

    while(l< h){
         m = l + ( (h-l)/2 );
        if( a[m] > x)
             h = m;
        else l = m +1;
    }
    return l;
}

int lowerBound(long long x){

    int l=0, h = n-1,m;

    while(l<h){
        m = l + ( (h-l+1)/2 );
        if(a[m] >= x)
             h = m-1;
        else l = m;
    }
    return l;
}

int main(){

    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i);

    scanf("%d",&q);
    while(q--){
        scanf("%lld",&qi);

        int l = lowerBound(qi);
        int  h = upperBound(qi);

        if(l==0 && a[l]>=qi) printf("X ");
        else printf("%lld ",a[l]);

        if(h==n-1 && a[h]<=qi) printf("X\n");
        else printf("%lld\n",a[h]);
    }
}
