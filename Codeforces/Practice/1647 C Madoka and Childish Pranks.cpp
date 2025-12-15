#include <bits/stdc++.h>

using namespace std;

int t, n, m;

struct edge{
    int a,b,c,d;
    edge(int a, int b, int c, int d) : a(a), b(b),c(c), d(d) {}
};

void solve(){

    cin >> n >> m;

    vector<string> g (n);
    for(int i=0;i<n;i++)
        cin >> g[i];

    if(g[0][0] == '1'){
        cout << -1 << "\n";
        return;
    }

    vector<edge> ans;
    for(int j=0;j<m;j++)
        for(int i=n-1;i>=1;i--)
            if(g[i][j] == '1' )
                ans.push_back(edge( i , j + 1 , i + 1, j + 1) );

    for(int j=m-1;j>=1;j--)
        if(g[0][j] == '1' )
            ans.push_back(edge(1 , j, 1, j +  1 )) ;

    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i].a << " " <<  ans[i].b << " " << ans[i].c << " " << ans[i].d << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
