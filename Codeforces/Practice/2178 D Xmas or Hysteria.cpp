#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define f first
#define s second

int t, n, m, x;

void solve(){

    cin >> n >> m;

    vector< pair<int,int> > v;
    for(int i=1;i<=n;i++)
        cin >> x, v.push_back({x, i});

    if(m*2 > n ){
        cout << -1 << "\n";
        return;
    }

    sort(v.begin(), v.end());

    vector< pair<int,int> > ans;

    if(m > 0){
        for(int i = 1 ; i <=n-(m*2) ; i++)
            ans.push_back({v[i].s, v[i-1].s });

        for(int i=n-1; i >= n-m; i--)
            ans.push_back({ v[i].s , v[i-m].s });
    }else{

       ll target = v[n-1].f, acc = 0;
       for(int i=n-2;i>=0;i--){
            acc += v[i].f;
            if(acc >= target){
                for(int j=0; j < i; j ++)
                    ans.push_back({v[j].s, v[j+1].s });
                for(int j=i; j < n-1; j ++)
                    ans.push_back({v[j].s, v[n-1].s });

                break;
            }
       }
    }

    if(ans.empty()){
        cout << -1 << "\n";
        return;
    }

    cout << ans.size() << "\n";
    for(int i=0;i < ans.size(); i++)
        cout << ans[i].f << " " << ans[i].s << "\n";
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();
}
