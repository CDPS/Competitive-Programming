#include <bits/stdc++.h>

using namespace std;

int t = 1, n, k, p, x;

void solve(){
    cin >> n >> k >> p;

    vector<int> even, odd;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x % 2 != 0) odd.push_back(x);
        else           even.push_back(x);
    }

    if(odd.size() < k - p){
        cout << "NO\n";
        return;
    }

    int odd_rem = odd.size() - (k - p);
    if(odd_rem % 2 != 0){
        cout << "NO\n";
        return;
    }

    if(even.size() + (odd_rem / 2) < p){
        cout << "NO\n";
        return;
    }

    cout << "YES" << "\n";
    vector<vector<int>> ans(k);

    int odd_idx = 0, even_idx = 0;

    for(int i = 0; i < k - p; i++)
        ans[i].push_back(odd[odd_idx++]);

    for(int i = k - p; i < k; i++)
        if(even_idx < even.size())
            ans[i].push_back(even[even_idx++]);
        else
            ans[i].push_back(odd[odd_idx++]), ans[i].push_back(odd[odd_idx++]);

    while(even_idx < even.size())
        ans[0].push_back(even[even_idx++]);

    while(odd_idx < odd.size())
        ans[0].push_back(odd[odd_idx++]);

    for(int i = 0; i < k; i++){
        cout << ans[i].size() << " ";
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " \n"[j == ans[i].size() - 1];
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
