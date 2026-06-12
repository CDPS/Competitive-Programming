#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m, k;

int a[50];

int solve(){

    cin >> n >> m >> k;
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a, a + n , greater<int>());

    int ans = 0 ;
    for(int i=0;i<n && m > 0;i++, k--){
        if(k >= m )
            return ans;
        m = (k > 0)? m - min(a[i], m) : m + 1 - min(a[i], m + 1);
        ans++;
    }

    return m == 0? ans : -1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}

