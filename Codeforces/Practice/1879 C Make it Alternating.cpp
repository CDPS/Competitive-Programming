#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
const ll  m    = 998244353;
const int MAXN = 200000;

ll factorial[200005];

string s;

void build(){
    factorial[0] = factorial[1] = 1;
    for(int i=2;i<=MAXN;i++)
        factorial[i] = (factorial[i-1] *(ll)i)%m;
}

void solve(){

    cin >> s;

    ll  mul = 1, sum = 0, curr = 1;
    for(int i=1;i<s.size();i++){
        if(s[i]== s[i-1]){ curr++; continue; }
        sum+= curr-1;
        mul = (mul*curr)%m;
        curr = 1;
    }

    sum+= curr-1;
    mul = (mul*curr)%m;

    cout << sum << " " << (mul*factorial[sum])%m << "\n";
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    build();

    cin >> t;
    while(t--)
        solve();

    return 0;
}

