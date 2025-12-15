#include <bits/stdc++.h>

using namespace std;

int n, k, d, w;
int day[3002];

int solve(){

    cin >> n >> k;
    while(n--)
        cin >> d >> w, day[d] += w;

    int ans = 0;
    for(int i=1;i<=3001;i++){
        int currk = k;
        int take = min(day[i-1], currk);
        currk -=take;
        ans   +=take;
        take = min(currk, day[i]);
        day[i]-= take;
        ans+= take;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
