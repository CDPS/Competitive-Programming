#include<bits/stdc++.h>

using namespace std;

int f(int n, int k){
    return n/k + (n%k!=0);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, k;
    cin >> t;

    while(t--){
        cin >> n >> k;
        cout << ( n%2? 1 + f(n-k, k-1) : f(n, k-1) )<< "\n";
    }
    return 0;
}
