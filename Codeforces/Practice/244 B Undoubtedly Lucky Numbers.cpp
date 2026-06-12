#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 1e9;

ll n;

set<ll> st;
void build(ll curr, int a, int b){

    if(curr > MAX ) return;
    if (curr > 0 && curr <= 1e9)
        st.insert(curr);
    if (curr > 0 || a > 0) build(curr*10 + a, a, b);
    if (curr > 0 || b > 0) build(curr*10 + b, a, b);
}

void gen(){
    for(int i=0; i<=9; i++)
        for(int j = i; j <=9; j++)
            build(0, i , j );
}

ll solve(){

    cin >> n;

    gen();

    int ans = 0;
    for (ll x : st)
        ans+= x <= n;

    return ans;
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    int t = 1;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
