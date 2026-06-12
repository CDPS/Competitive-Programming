#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n;
string s;

ll solve(){

    cin >> s; n = s.size();

    ll heavy_count = 0, ans = 0;
    for(int i=0;i < n - 4; i++){
        if(s[i] == 'h' && s[i+1] == 'e' && s[i+2] == 'a' && s[i+3] == 'v' && s[i+ 4] == 'y')
            heavy_count++;
        if(s[i] == 'm' && s[i+1] == 'e' && s[i+2] == 't' && s[i+3] == 'a' && s[i+ 4] == 'l')
            ans+= heavy_count;
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
