#include <bits/stdc++.h>

using namespace std;

int n, t;
int a[200000];

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> sfx(n), pfx(n);

    sfx[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--) sfx[i] = max(a[i], sfx[i+1]);

    pfx[0] = a[0];
    for(int i=1;i<n;i++) pfx[i] = min(a[i], pfx[i-1]);


    bool check = true;
    vector<pair<int,int> > ans;
    for(int i=0;i<n-1;i++){
        if(pfx[i] > sfx[i+1]){
            check = false;
            ans.clear();
            break;
        }

        if(a[i] >  sfx[i+1] )
             ans.push_back({pfx[i], sfx[i+1]});
        else
            ans.push_back({a[i], sfx[i+1]});
    }

    cout << ( check ? "YES" : "NO" ) << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i].first << " " <<ans[i].second << "\n";
}

int main(){

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

