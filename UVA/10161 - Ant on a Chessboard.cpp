#include <bits/stdc++.h>

using namespace std;

long long f(long long n){
    return n*n;
}

long long binarySearch(long long n){

    long long l = 0, h = 44722ll, m;

    while(l<h){
        m  = l + (h-l)/2ll;
        if(f(m)>= n)
            h = m;
        else
            l = m+1ll;
    }
    return l;
}

int main(){

    long long n;

    while(scanf("%lld",&n) && n){

        long long level = binarySearch(n);

        long long pos = n - (f(level-1ll) +1ll) +1ll;

        long long points = (2ll*level) -1ll;

        long long middle = (points/2ll)+1ll;

        long long x,y;

        if(level%2==0){
            if(pos>=middle)
                x = level, y = level - (pos-middle);
            else
                y = level, x = (middle) +(pos-middle);
        }else{
            if(pos>=middle)
                 y = level, x = level - (pos-middle);
            else
                 x = level, y = (middle) +(pos-middle);
        }
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
