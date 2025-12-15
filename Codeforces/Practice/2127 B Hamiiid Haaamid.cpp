#include <bits/stdc++.h>

using namespace std;

int t, n, x ;
string s;

int solve(){

    cin >> n >> x >> s;

    int pfx = -1e9;
    for(int i=x-1; i >=0;i--)
        if(s[i] == '#'){
            pfx = i; break;
        }

    int sfx = 1e9;
    for(int i=x; i < n ;i++)
        if(s[i] == '#'){
            sfx = i; break;
        }

    if(sfx == 1e9 && pfx == -1e9)
        return 1;

    if(x == 1 || x == n)
        return 1;

    return max(min(x, n-sfx+1), min(pfx + 2, n-x+1)) ;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve()  << "\n";

    return 0;
}
