#include <bits/stdc++.h>

using namespace std;

int n, k;
void solve(){

    cin >> n >> k;

    if(k==0){
        for(int i=0;i<n;i++) cout << 0;
        cout <<"\n";
        return;
    }

    if(n == k){
        for(int i=0;i<n;i++) cout << 1;
        cout <<"\n";
        return;
    }

    if(k==1){
        cout << 1;
        for(int i=0;i<n-1;i++) cout << 0;
        cout <<"\n";
        return;
    }

    cout << 1;
    for(int i=0;i<n-k-1;i++) cout << 0;
    for(int i=0;i<k-2;i++) cout << 1;
    cout << 10 <<"\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
    return 0;
}
