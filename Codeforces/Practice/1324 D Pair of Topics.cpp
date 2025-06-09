#include <bits/stdc++.h>

using namespace std;

int a[200000];
int b[200000];
int c[200001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;

    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    c[0] = 1e9*-1;
    for(int i=0;i<n;i++) c[i+1] = b[i] - a[i];
    sort(c, c + n + 1);

    long long ans = 0;
    for(int i=0;i<n;i++){
        auto it = lower_bound(c, c + n + 1, a[i]-b[i] );
        ans += int(it - c) - 1 - (a[i]>b[i]);
    }

    cout << ans/2 << "\n";

    return 0;
}
