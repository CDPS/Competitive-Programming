#include <bits/stdc++.h>

using namespace std;

int t = 1, n, x;
int p[100001];

int solve(){

    cin >> n;

    for(int i=0;i<n;i++)
        cin >> x, p[x] = i;

    int maxi = 1, curr = 1;
    for (int i = 2; i <= n; i++) {
        curr = (p[i] > p[i - 1])? curr + 1 : 1;
        maxi = max(maxi, curr);
    }

    return n - maxi;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
