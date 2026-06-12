#include <bits/stdc++.h>

using namespace std;

int t, a, b;

int f(int x){
    int curr = a, div = 0;
    while(curr > 0)
        curr/=x, div++;
    return x-b + div;
}

int solve(){

    cin >> a >> b;

    if(a == 0) return 0;

    int fix = max(b, 2), ans = 1e9;
    for(int x = fix; x <= fix + 30; x++)
        ans = min(ans, f(x));

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
