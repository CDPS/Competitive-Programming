#include <bits/stdc++.h>

using namespace std;

const long MAX= 400000019;

long zeros(long n){
    long ans =0;
    while(n>0){
        ans = ans + (n/5);
        n/=5;
    }
    return ans;
}

long binarySearch(long t){

    long l =0, h =MAX;

    while(l < h){
        long m = l + ( (h-l)/2 );
        if( zeros(m) >= t)
            h = m;
        else
            l = m+1;
    }

    return ( zeros(l) == t )? l: -1;
}

int main(){

    int t,caseno=1;
    scanf("%d",&t);
    long q;
    while(t--){
        scanf("%ld",&q);

        long ans = binarySearch(q);

        if(ans==-1) printf("Case %d: impossible\n",caseno++);
        else printf("Case %d: %ld\n",caseno++,ans);
    }
    return 0;
}
