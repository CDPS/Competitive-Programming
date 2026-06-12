#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200000];

void solve(){

    cin >> n;

    vector< vector<pair<int,int>> > g(30);

    for(int i=0; i < n; i++){
        cin >> a[i];
        for(int bit=29; bit >=0; bit--){
            if( (a[i]&(1<<bit)) != 0 )
                g[bit].push_back({a[i], i});
        }
    }

    vector<bool> in_set(n);
    vector<int> ans;

    int maxi = 0;
    for(int bit=29; bit >=0; bit--){

        if( (maxi &(1<<bit)) != 0 ) continue;

        int curr = maxi, idx = -1;
        for(auto x : g[bit])
            if( (maxi | x.first) > curr )
                curr = maxi |x.first, idx = x.second;

        if(idx != -1 ){
            in_set[idx] = true;
            ans.push_back(a[idx]);
            maxi = curr;
        }
    }

    for(int i=0; i<n; i++)
        if( !in_set[i] )
            ans.push_back(a[i]);

    for(int i=0; i < n; i++)
        cout << ans[i] << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
