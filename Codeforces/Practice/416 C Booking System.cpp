#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int t = 1, n , m, x, y;

bool vs[1000];

void solve(){

    cin >> n;

    vector< pair<int, pair<int, int> > > v(n);
    for(int i=0;i<n;i++){
        cin >> x >> y;
        v[i].f = x;
        v[i].s.f = y;
        v[i].s.s = i + 1;
    }

    cin >> m;
    vector<pair<int, int>> a(m);
    for(int i=0;i<m;i++){
        cin >> x;
        a[i].f = x; a[i].s = i + 1;
    }

    sort(v.begin(), v.end(), [&] (auto a, auto b){
        return a.s.f > b.s.f;
    } );

    sort(a.begin(), a.end());

    int sum = 0;
    vector< pair<int,int>  > ans;
    for(int i=0;i< n; i++){
        for(int j = 0; j < m; j++){
            if( v[i].f <= a[j].f && !vs[j] ){
                ans.push_back({ v[i].s.s, a[j].s } );
                vs[j] = true;
                sum += v[i].s.f;
                break;
            }
        }
    }

    cout << ans.size() << " " << sum << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i].f << " " << ans[i].s << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}


