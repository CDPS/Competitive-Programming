#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;

ll a[500000];
ll b[500000];
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n; ll m;
    cin >> t;

    while(t--){

        cin >> n >> m;

        for(int i = 0; i < n; i++)
            cin >> a[i], b[i] = a[i];

        sort(b, b + n);

        int ans = 0;
        for(; ans < n && b[ans] <= m; ++ans){
            m -= b[ans];
        }

        if(ans > 0 && ans < n && m + b[ans-1] >= a[ans])
                ++ans;

        cout << (n + 1 - ans) << "\n";
    }
    return 0;
}
