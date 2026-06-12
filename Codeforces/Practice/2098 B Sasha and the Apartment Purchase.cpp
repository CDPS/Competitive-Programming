#include <bits/stdc++.h>

using namespace std;

int t, n , k;
int a[100000];

int solve(){

    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> a[i];

    sort(a, a+ n);

    int m = n - k;
    int l = (m - 1) / 2;
    int r = n - 1 - l;

    return a[r] - a[l] + 1;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve()  << "\n";
}

