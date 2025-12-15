#include <bits/stdc++.h>

using namespace std;

int t, n;
int pfx[2001];

int solve(){

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> pfx[i], pfx[i]+= pfx[i-1];

    int ans = n;
    for(int i=1;i<=n;i++){
        int target = pfx[i];
        int acc = i;
        int r = i + 1, l = i + 1;
        while(r<=n){
            if(pfx[r] - pfx[l-1] == target){
                acc = max(acc, r-l+1 ); l= ++r;
                continue;
            }
            r++;
        }
        if(l == n + 1 && r== n + 1)
            ans = min(ans, acc);
    }

    return ans;
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
