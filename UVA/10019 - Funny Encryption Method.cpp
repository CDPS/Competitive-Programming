#include <bits/stdc++.h>

using namespace std;

long bits(long n){
    long res=0;
    while(n){
        int d = n%2;
        res+= d;
        n/=2;
    }
    return res;
}

long toHexa(long n){
    long res=0; int exp=0;
    while(n){
        int d = n%10;
        res+= d*(pow(16,exp));
        n/=10;
        exp++;
    }
    return res;
}
int main(){
    int t; long n;
    scanf("%d",&t);
    while(t--)
     scanf("%ld",&n), printf("%ld %ld\n",bits(n),bits(toHexa(n)));
    return 0;
}
