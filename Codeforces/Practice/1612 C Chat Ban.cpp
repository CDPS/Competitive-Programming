#include <bits/stdc++.h>

using namespace std;

#typedef ll long long;


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t, n, x, m, mini, maxi, l , r;
    cin >> t;

    while(t--){

        cin >> n >> x >> m;
        mini = maxi = x;

        while(m--){
            cin >> l >> r;
            if( (l<= mini && r>=maxi) ||
                (r >= mini && r<= maxi) ||
                (l >= mini && l<= maxi) ){
                mini = min(mini, l);
                maxi = max(maxi, r);
            }
        }

        cout << maxi - mini + 1 << "\n";    }
    return 0;
}

