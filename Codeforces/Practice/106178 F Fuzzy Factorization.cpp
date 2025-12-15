#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;

void solve(){

    cin >> s;

    string sp;

    int sz = min((int)s.size(), 13);
    for(int i=0;i<sz;i++)
        sp += s[i];

    map<ll,int> mp;
    for(int i=0;i < (int)s.size() - sz;i++)
        mp[2]++, mp[5]++;

    ll x  = stoll(sp);
    for(ll p=2;p*p<= x; p++)
        while(x%p == 0)
            mp[p]++, x/=p;

    if(x > 1)
        mp[x]++;

    cout << mp.size() << "\n";
    for(auto it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
