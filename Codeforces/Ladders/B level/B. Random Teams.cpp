//thansk fabo <3
#include <bits/stdc++.h>

using namespace std;

long long  nC2(long long n){
    return (n*(n-1))/2;
}

int main(){

    long long n,m;

    cin >> n >> m;

    long long maxi = nC2(n-m+1);


    long long d = n/m;
    long long mod = n%m;

    long long mini = ( (m-mod)*(nC2(d)) )+ ( (mod)*(nC2(d+1) ) );
    cout << mini << " " << maxi << "\n";
    return 0;
}
