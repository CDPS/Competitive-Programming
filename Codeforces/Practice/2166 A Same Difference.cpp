#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int solve(){

    cin >> n >> s;

    char target = s[n-1];

    int ans = 0;
    for(int i=0; i < n ; i++)
        ans += (s[i] != target);
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
