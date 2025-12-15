#include <bits/stdc++.h>

using namespace std;

int n, x;

int solve(){

    cin >> n;

    vector<bool> a(5001, false);
    for(int i=0;i<n;i++)
        cin >> x, a[x] = true;

    int ans = 0;
    for(int i=1;i<=n;i++)
        ans+= (!a[i]);

    return ans;
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
