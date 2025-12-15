#include<bits/stdc++.h>

using namespace std;

int t, n;
int a[100000];

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    for(int k=0,i=0;k<n;k++){

        while(i <= k && a[i] < k-i+1 )
            i++;

        cout << k-i+1 << " \n"[k==n-1];
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
