#include <bits/stdc++.h>

using namespace std;

int t, n;

void solve(){

    cin >> n;

    vector<int> p = {1, 0};
    for(int i = 2; i <= n; i++){

        for(int &x : p) x = 2 * x + 1;

        int limit = (1 << (i-1));
        for(int j = 0; j < limit; j++)
            p.push_back(2 * j);
    }

    for(int i = 0; i < p.size(); i++)
        cout << p[i] << " \n"[i==p.size()-1];
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();
}
