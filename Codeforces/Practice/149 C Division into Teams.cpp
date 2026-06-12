#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pii pair<int,int>

int t = 1, n;

vector<int> ans[2];
void solve(){

    cin >> n;

    vector<pii> a(n);
    for(int i=0; i < n; i++)
        cin >> a[i].f, a[i].s  = i + 1;

    sort(a.begin(),  a.end());

    for(int i = 0; i < n; i++)
        ans[i%2].push_back(a[i].s);

    cout << ans[0].size() << "\n";
    for(int i=0; i < ans[0].size(); i++)
        cout << ans[0][i] << " \n"[i==ans[0].size()-1];

    cout << ans[1].size() << "\n";
    for(int i=0; i < ans[1].size(); i++)
        cout << ans[1][i] << " \n"[i==ans[1].size()-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
