#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

void solve(){

    cin >> n >> s;

    string t = s;
    sort(t.begin(), t.end());

    if(t == s){
        cout << "Bob" << "\n";
        return;
    }

    vector<int> ans;
    for(int i=0;i<n;i++)
        if(s[i] != t[i])
            ans.push_back(i+1);

    cout << "Alice" << "\n" << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)\
        cout << ans[i] << " \n"[i==ans.size()-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}



