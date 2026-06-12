#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000];
int b[1000];

int solve(){

    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int ans = 0;
    for(int j=0, ora = 0, orb = 0;j<n;j++)
        ora|= a[j], orb|= b[j], ans = max(ans, ora + orb);

    return ans;
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
