#include <bits/stdc++.h>

using namespace std;

int a [100000];
int n;

int binarySearch(int l, int h, int t){

    while(l <= h){
        int m = (l+h)/2;
        if(a[ m] == t) return m;
        else if( t < a[m]) h = m-1;
        else l = m+1;
    }
    return -1;
}

//Finds the first element
//where the predicate is true
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

//Finds the last element (index)
//where the predicate is false
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

//bisection method
double binarySearch(){

    double l=0, h=1,m;

    int t=100;
    while(t--){
        m = (l+h)/2;
        if( f(m) * f(l) > 0 )
            l = m;
        else
            h=m;
    }
    return m;
}

int main(){

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    int m;
    scanf("%d",&m);
    int aux;

    for(int i=0;i<m;i++){
        scanf("%d",&aux);
        printf("%d\n",binarySearch(0,n-1,aux));
    }
    return 0;
}
