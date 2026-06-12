#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
int a[3000];

int solve(){

    cin >> n;

    int maxi = -1;
    for(int i=0;i<n;i++)
        cin >> a[i], maxi = max(a[i], maxi);

    return maxi*n;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}


