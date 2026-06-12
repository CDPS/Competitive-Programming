#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;
int n, p;
string s;

int solve(){

    cin >> n >> p >> s;

    p--;
    if( p >= n/2)
        p = n-1-p;

    int ans = 0, mini = oo, maxi = -1 ;
    for(int i=0;i<n/2;i++){
        if(s[i] != s[n-1-i]){
            ans +=  min(abs(s[i] -  s[n-1-i]), 26 - abs(s[i] -  s[n-1-i]));
            mini = min(i, mini);
            maxi = max(i, maxi);
        }
    }

    if(mini != oo)
        ans += (maxi-mini) + min( abs(p-maxi), abs(p-mini) );

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
