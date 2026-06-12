#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9 + 7;

int t = 1, k, n;

map<int, int> mp;
int f(int x, int curr){

    if(x == k) return mp[x] = curr;
    if(x < k ) return mp[x] = oo;

    if(mp.count(x) )
        return mp[x];

    if(x%2 == 0)
        return mp[x] = f(x/2, curr + 1);

    int div = x/2;
    if(div %2 == 0) div++;

    return mp[div] = min( f(div, curr+1 ), f(x - div, curr+ 1));
}

int solve(){
    cin >> n >> k;
    mp.clear();
    int ans = f(n, 0);
    return ans == oo? -1 : ans ;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}


