#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

void solve(){

    cin >> n >> s;

    vector<vector<int>> acc(2, vector<int>());

    for(int i=0;i < n;i++)
        acc[  s[i] -'0'].push_back(i + 1);

    if(acc[0].size() == n) {
        cout << 0 << "\n";
        return;
    }

    if(acc[0].size() %2 == 1){
        cout << acc[0].size() << "\n";
        for(int i = 0;i < acc[0].size();i++)
            cout << acc[0][i] << " \n"[i==acc[0].size()-1];
        return;
    }

    if(acc[1].size()%2 == 0){
        cout << acc[1].size() << "\n";
        for(int i = 0;i < acc[1].size();i++)
            cout << acc[1][i] << " \n"[i==acc[1].size()-1];
        return;
    }

    cout << - 1 << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
