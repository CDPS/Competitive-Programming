#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, x;

int solve(){

    cin >> n;

    int maxi = -1, ans = 0;
    for(int i=0;i<n;i++){
        cin >> x;
        if(x > maxi)
            ans++, maxi = x;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}

