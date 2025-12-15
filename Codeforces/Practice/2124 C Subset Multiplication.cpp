#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[600000];

int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a / __gcd(a, b)) * b;
}

int solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int ans = 1;
    for(int i=1;i<n;i++)
        if(a[i] % a[i-1] != 0)
            ans = lcm(a[i-1]/__gcd(a[i-1], a[i]), ans);

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
