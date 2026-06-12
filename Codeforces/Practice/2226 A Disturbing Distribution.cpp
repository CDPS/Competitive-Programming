#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int a[100];

int solve(){

    cin >> n;
    for(int i=0; i < n ; i++) cin >> a[i];

    int ans = 0;
    bool theres_one = false;

    for(int i=0; i < n; i++){

        if(a[i] != 1)
            ans+= a[i], theres_one = false;
        if(a[i] == 1)
            theres_one = true;
    }

    return ans + theres_one;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

