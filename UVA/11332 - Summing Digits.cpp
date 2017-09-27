#include <bits/stdc++.h>

using namespace std;

int sum(long n){
    int res=0;
    while(n){
        res+=n%10;
        n/=10;
    }
    return res;
}

long f(long n){
    while(n>=10){
        n = sum(n);
    }
    return n;
}

int main(){

    long n;
    while(cin >> n && n){
        cout << ( n%9==0 ? 9 : (n%9) )  << "\n";
    }
    return 0;
}

