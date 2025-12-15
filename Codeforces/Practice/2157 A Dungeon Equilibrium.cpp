#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int solve(){

    cin >> n;

    vector<int> a(101, 0);
    for(int i=0;i<n;i++)
        cin >> x, a[x]++;

    int ans = 0;
    for(int i=0;i<=100;i++)
            ans+= a[i] < i ? a[i] : a[i] - i;
    return ans;
}

int main(){

    cin.tie(NULL); cin.sync_with_stdio(false);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

