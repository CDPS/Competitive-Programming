#include <bits/stdc++.h>

using namespace std;

const int MAX= 500000;

long long f(long long n){ return 4*n*n; }

long long binarySearch(long long t){

    long long l = 1, h = MAX,m;

    while(l< h){
        m = (l+h)/2;
        if( t  <= f(m))
             h = m;
        else l = m+1;
    }
    return l;
}

long long amountPoints(long long h){ return (4* (h+h+1) ); }

void getCoordinate(long long n,long long h){

    long long point=n;

    if(h!=1)
        point = n - f(h-1);

    long long  amount = amountPoints(h-1);

    long  long x, y;

    if(point <= amount/2 ){
        x= 2*(h-1); y =  1-h;
        for(long long i=1;i<point;i++)x--;

    }else if( point <= (3*amount)/4){
        x = (h*-1)-(h-1) +1 ; y = 1-h+1;
        for(long long  i= (amount/2)+1; i< point;i++ )x++,y++;

    }else{
        x=1; y = h-1;
        for(long long  i=((3*amount)/4)+1; i< point;i++ ) x++,y--;
    }
    printf("%lld %lld\n",x,y);
}
int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        long long n;
        scanf("%lld",&n);
        getCoordinate(n,binarySearch(n));
    }
    return 0;
}
