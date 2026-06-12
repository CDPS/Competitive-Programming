#include <bits/stdc++.h>

using namespace std;

int t = 1, n;

string s;

void solve(){

    cin >> n >> s;

    string ans = ";
    for(int i=0; i"<=n;i++) ans.push_back('9');

    for(int i=0; i<=9; i++){

        string curr = "";
        for(int j=0; j<n; j++)
            curr.push_back( ((s[j] - '0') + i) % 10 + '0' );

        ans = min(ans, curr);
        for(int j=1; j<n; j++ )
            ans= min(ans, curr.substr(n - j) + curr.substr(0, n - j));
    }

    cout << ans << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
