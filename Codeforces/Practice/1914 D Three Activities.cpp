#include <bits/stdc++.h>

using namespace std;

int n, t, x;

priority_queue< pair<int,int> >  g[3];

pair<int,int> a[3][3];

long long solve(){

    for(int i=0;i<3;i++)
        while(!g[i].empty())
            g[i].pop();

    cin >> n;
    for(int i=0;i<3;i++)
        for(int j=0;j<n;j++)
            cin >> x, g[i].push({x,j});

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[i][j] = g[i].top(), g[i].pop();

    int ans = 0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                if( a[0][i].second != a[1][j].second && a[0][i].second != a[2][k].second  && a[1][j].second != a[2][k].second )
                    ans= max(ans, a[0][i].first +  a[1][j].first + a[2][k].first);

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
