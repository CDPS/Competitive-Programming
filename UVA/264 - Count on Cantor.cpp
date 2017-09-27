#include <bits/stdc++.h>

using namespace std;

long long f(long long n){
    return (n*(n+1ll))/2ll;
}

long long binarySearch(long long t){
    long long l=0,h=t,m;
    while(l< h){
        m = (l+h)/2ll;
        if( t  <= f(m) )
             h = m;
        else l = m+1ll;
    }
    return l;
}

void getTerm(long long level, long long t){

    long long res1= t - f(level-1ll),res2=(level - res1)+1ll;

    if(level%2)
        printf("TERM %lld IS %lld/%lld\n",t,res2,res1);
    else
        printf("TERM %lld IS %lld/%lld\n",t,res1,res2);
}

int main(){
    long long n;
    while(cin >> n)
        getTerm(binarySearch(n),n);
    return 0;
}
