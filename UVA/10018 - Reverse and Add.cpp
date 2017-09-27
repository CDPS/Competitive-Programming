#include <bits/stdc++.h>

using namespace std;

long reverseN(long n){
    long res=0;
    while(n){
        int d = n%10;
        res= res*10 + d;
        n/=10;
    }
    return res;
}

bool isPal(long n){
    long m = reverseN(n);
    if(m==n) return true;
    return false;
}

int main(){

    int t; long n;

    scanf("%d",&t);

    while(t--){
        scanf("%ld",&n);
        int i=0;
        while(!isPal(n)){
            n+=reverseN(n);i++;
        }
        printf("%d %ld\n",i,n);
    }
    return 0;
}
