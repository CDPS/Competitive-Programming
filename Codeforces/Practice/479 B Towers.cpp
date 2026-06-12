#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pii pair<int, int>

int t =1, n, k, x;

void solve(){

    cin >> n >> k;

    vector<pii> a;
    for(int i=0; i < n; i++)
        cin >> x, a.push_back({x, i + 1});

    sort(a.begin(), a.end());

    int mini = a[n-1].f - a[0].f;
    int idx  = 0;
    vector<pii> ans;

    for(int i=1; i<= k; i++){

        a[n-1].f--; a[0].f++;
        ans.push_back({a[n-1].s, a[0].s });
        sort(a.begin(), a.end());

        if( a[n-1].f - a[0].f < mini )
            idx = i, mini = a[n-1].f - a[0].f;
    }

    cout << mini << " " << idx << "\n";
    for(int i=0; i < idx; i++)
        cout << ans[i].f << " " << ans[i].s << "\n";
}


int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
