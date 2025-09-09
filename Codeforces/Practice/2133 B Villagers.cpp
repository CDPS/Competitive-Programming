#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int a[200000];

ll solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a, a + n, greater<int>());

    ll ans = 0;
    for(int i=0;i<n;i+=2)
        ans+=a[i];

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}

