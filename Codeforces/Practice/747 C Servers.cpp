#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, q, t, k, d;
int a[101];

int solve(){

    cin >> t >> k >> d;

    int acc = 0;
    for(int i=1;i<=n;i++)
        if( a[i] < t )
            acc++;

    if(acc < k) return -1;

    int ans = 0;
    for(int i=1, j=1;i<=n && j <= k; i++ )
        if(a[i] < t )
            a[i] = t + d -1, j++, ans += i ;

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> q;
    while(q--)
        cout << solve() << "\n";
}
