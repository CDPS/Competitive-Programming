#include <bits/stdc++.h>

using namespace std;

int n, t = 1;

void solve(){

    cin >> n;

    vector<int> ans (1, n);
    for(int p=2; p*p <= n; p++)
        while(n%p==0)
             ans.push_back(n/p), n/=p;

    if(n!= 1)
        ans.push_back(1);

    for(int i=0;i < ans.size();i++)
        cout << ans[i] << " \n"[i==ans.size()-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
