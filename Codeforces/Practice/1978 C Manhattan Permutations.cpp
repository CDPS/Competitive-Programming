#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll k;

void solve(){

    cin >> n >> k;

    ll sumax = 0;
    for(int i=1;i<=n;i++)
        sumax += abs( i-(n-i+1) );

    if(k%2 || k > sumax ){
        cout << "NO" << "\n";
        return;
    }

    vector<int> a(n);
    for(int i=1;i<=n;i++)
        a[i-1] = i;

    int i = 0, j = n-1;
    while(i < j && k){
        if(k >= 2ll*(j - i))
            swap(a[i], a[j]), k-= 2ll*(j - i), i++, j-- ;
        else
            swap(a[i], a[(k/2) + i ]), k = 0;
    }

    cout << "YES" << "\n";
    for(int i=0;i<n;i++)
        cout << a[i] << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
