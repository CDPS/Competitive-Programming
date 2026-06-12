#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

void solve(){

    cin >> n >> s;

    map< pair<int, int>, int > mp;
    for(int i=0, K= 0, D= 0; i <n; i++){

        if(s[i] == 'D') D++;
        else K++;

        int div = __gcd(D, K);

        mp[{D/div, K/div}]++;
        cout <<  mp[{D/div, K/div}] << " \n"[i==n-1];
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
