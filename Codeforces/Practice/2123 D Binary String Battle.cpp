#include <bits/stdc++.h>

using namespace std;

int t, n, k;
string s;

bool solve(){

    cin >> n >> k >> s;

    if(k > n/2 ) return true;

    int ones = 0;
    for(int i=0;i<n;i++)
        ones += s[i] == '1';
    return ones <= k;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "Alice" : "Bob" ) << "\n";
    return 0;
}
