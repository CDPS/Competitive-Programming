#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int solve(){

    cin >> n;

    int ans = -1;
    for(int i=0;i<n;i++)
        cin >> x, ans = max(x, ans);

    return ans;
}
int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
        cout << solve() << "\n";
    return 0;
}
