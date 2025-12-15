#include <bits/stdc++.h>

using namespace std;

int t, n, rk, ck, rd, cd;

int solve(){

    cin >> n >> rk >> ck >> rd >> cd;

    int ans1 = (rd > rk)? rd    : 0;
    int ans2 = (rd < rk)? n -rd : 0;
    int ans3 = (cd > ck)? cd    : 0;
    int ans4 = (cd < ck)? n -cd : 0;

    return max( {ans1, ans2,ans3, ans4});
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
