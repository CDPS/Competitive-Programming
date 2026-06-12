#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int x, y, a, b;

void solve(){

    cin >> x >> y  >> a >> b;

    vector< pair<int,int> > ans;
    for(int i = a; i <= x; i++)
        for(int j=b; j<=y;j++)
            if( i > j)
                ans.push_back({i, j});

    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i].f << " " << ans[i].s << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}

