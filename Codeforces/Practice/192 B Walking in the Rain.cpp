#include <bits/stdc++.h>

using namespace std;

int t = 1, n;

int a[1000];

int solve(){

    cin >> n;

    for(int i=0; i < n;  i++) cin >> a[i];

    a[1] =  min(a[0], a[1]);
    for(int i=2; i < n; i++)
        a[i] = min(a[i], max( a[i-1], a[i-2]));

    return a[n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
