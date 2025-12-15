#include <bits/stdc++.h>

using namespace std;

int n;
int mini = 1e9 + 7;
int a[200000];

long long solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i], mini = min(mini, a[i]);

    int maxi = -1, curr = 0;
    for(int i=0; i < 2*n; i++) {
        if (a[i % n] > mini)
            curr++;
        else
            maxi = max(maxi, curr), curr = 0;
    }

    maxi = max(maxi, curr);
    return 1ll*n*mini +  maxi;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}

