#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll h, n;

ll solve(){

    cin >> h >> n;

    ll ans = 0;
    bool mandatory_path = 0;
    while( h >= 1){

        ll mid = 1ll << (h-1);

        bool ideal_path = n > mid;
        if(ideal_path == mandatory_path)
            mandatory_path^=1, ans++;
        else
            ans+= (1ll << h);

        if (ideal_path == 1)
            n -= mid;

        h--;
    }

    return ans;
}

int t = 1;
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
