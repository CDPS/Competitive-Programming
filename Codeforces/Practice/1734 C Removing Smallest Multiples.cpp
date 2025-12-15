#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, n;
string s;


ll solve(){

    cin >> n >> s;

    vector<int> factor(n+1);

    ll ans =0;
    for(int i=n;i>=0;i--)
        for(int j=i; j<=n && s[j-1]=='0';j+=i)
            factor[j] = i;

    for(int i=1;i<=n;i++)
        if(s[i-1]=='0')
            ans+=factor[i];

    return ans;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--)
        cout << solve() << "\n";

    return 0;
}
