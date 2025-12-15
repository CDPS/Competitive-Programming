#include <bits/stdc++.h>

using namespace std;

int t,n , x;

int solve(){

    cin >> n;

    int ans = 0, negatives = 0;
    for(int i=0;i<n;i++){
        cin >> x;
        if(x == 0) ans++;
        if(x<0) negatives++;
    }
    return ans + (negatives%2? 2 : 0);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
