#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int solve(){

    cin >> n >> s;

    int last_one = 0;
    for(int i=n-1;i>=0;i--)
        if(s[i]=='1'){
            last_one = i;
            break;
        }

    int ans = 0;
    for(int i=0, last_seen = -1e9;i<n; i++){
        if(s[i]=='0')
            ans = max( min( i-last_seen,   (i - last_one + n) % n ), ans);
        if(s[i] == '1')
            last_seen = i;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
