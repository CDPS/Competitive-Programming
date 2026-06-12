#include <bits/stdc++.h>

using namespace std;

int t = 1, n;

string s, tt;

void solve(){

    cin >> n;

    vector<string> a;

    map<string,string> mp;

    for(int i=0;i<n;i++){
        cin >> s >> tt;
        mp[tt] = s;
        a.push_back(tt);
    }

    set<string> processed;
    vector< pair<string, string> > ans;

    for(int i= a.size()-1;i>=0;i--){
        string curr = a[i];
        if( !processed.count(curr) ){

            while( mp.count(curr) )
                processed.insert(curr), curr = mp[curr];

            ans.push_back({curr, a[i]});
        }
    }

    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
