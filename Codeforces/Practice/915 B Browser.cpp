#include <bits/stdc++.h>

using namespace std;

int n, pos, l, r;

int solve(){

    cin >> n >> pos >> l >> r;

    if(l== 1 && r == n) return 0;
    if(l == 1 ) return abs(r - pos) + 1;
    if(r == n ) return abs(l - pos) + 1;

    return min(  abs(l - pos), abs(r - pos) ) + (r-l) + 2;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
