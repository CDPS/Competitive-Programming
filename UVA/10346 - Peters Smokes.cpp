#include <bits/stdc++.h>

using namespace std;

int main(){

    long n,k,res;
    while(cin >> n >> k){
        res =n ;
        while(n/k){ res+= n/k; n= (n-(k*(n/k)))+ (n/k); }
        cout << res << "\n";
    }
    return 0;
}
