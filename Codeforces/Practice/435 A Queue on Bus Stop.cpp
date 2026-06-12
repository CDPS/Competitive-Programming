#include <bits/stdc++.h>

using namespace std;

int t = 1, n, k, x;

int solve(){

    cin >> n >> k;

    int curr = 0, ans = 1;
    for(int i=0;i<n;i++){
        cin >> x;
        if(curr + x <= k)
            curr+=x;
        else
            ans++, curr = x;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}


