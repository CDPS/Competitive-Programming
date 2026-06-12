#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pi pair<int,int>

int n, m, k;

void solve(){

    cin >> n >> m >> k;

    vector<pi> v;
    for(int i=1;i<=n;i++){
        if(i%2)
            for(int j=1;j<=m;j++)
                v.push_back({i, j});
        else
            for(int j=m;j>=1;j--)
                v.push_back({i, j});
    }

    for(int i=0; i < k - 1; i++){
        cout << 2 << " ";
        cout << v[i*2].f     << " " << v[i*2].s   << " ";
        cout << v[i*2 + 1].f << " " << v[i*2+1].s << "\n";
    }

    cout << v.size() - (k-1)*2;
    for(int i=(k-1)*2; i < v.size(); i++)
        cout << " " << v[i].f     << " " << v[i].s;
    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
