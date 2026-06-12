#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int t = 1, n, k, x, y;

void solve(){

    cin >> n >> k;

    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
       cin >> x, a[i] = {x, i + 1};

    sort(a.begin(), a.end());

    vector<int> ans;
    for(int i=0; i <n && a[i].f <= k; k-=a[i].f, i++ )
        ans.push_back(a[i].s);

    cout << ans.size() << "\n";
    for(int i=0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i==ans.size()-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        solve();

    return 0;
}

