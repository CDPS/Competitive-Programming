#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200000];

int solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a+ n);

    int ans = -1;
    for(int i=1;i<n;i+=2)
        ans = max(ans,abs(a[i]-a[i-1]));

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
