#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int a[100];

ll solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    ll ans = 0;
    for(int i=0; i < n; i++){
        ll curr = 0;
        for(int j=i; j < n; j++)
            curr^=a[j], ans = max(ans, curr);
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cout <<  solve() << "\n";

    return 0;
}
