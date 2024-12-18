#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, m, a,b,c;
    cin >> t;

    while(t--){
        cin >> m >> a >> b >> c;
        int ans = 0;
        ans = (a > m )? ans + m : ans + a;
        ans = (b > m )? ans + m : ans + b;
        int remain = (2*m) - ans;
        ans = (c > remain )? ans + remain : ans + c;
        cout << ans << "\n";
    }
    return 0;
}


