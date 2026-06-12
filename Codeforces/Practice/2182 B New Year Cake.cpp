#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int f(int a, int b){

    int ans = 0;

    vector<int> v = {a, b};
    bool curr = 0;
    long long  p = 1;
    while(v[curr] >= p )
        v[curr]-=p, p*=2, curr = !curr, ans++;
    return ans;
}

int solve(){
    cin >> n >> m;
    return max(f(n,m), f(m,n));
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
