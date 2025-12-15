#include <bits/stdc++.h>

using namespace std;

int t, n, m, x;


int solve(){

    cin >> n >> m;

    vector<int> mp(m, 0);
    for(int i=0;i<n;i++)
        cin >> x, mp[x%m]++;

    int ans = mp[0] > 0;

    for(x=1;x<=m/2;x++){

        int xp = (m - (x % m)) % m;
        int maxi = max(mp[x], mp[xp]);
        int mini = min(mp[x], mp[xp]);

        if(maxi == 0) continue;
        else if(maxi > 0 && mini == 0)ans+= maxi;
        else if(maxi == mini) ans++;
        else ans+= 1 + (maxi - mini -1 );
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
