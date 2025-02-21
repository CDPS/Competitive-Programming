#include <bits/stdc++.h>

using namespace std;

int a[200002];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){
        cin >> n;


        for(int i=1;i<=n;i++) cin >> a[i];
        a[0] = a[1]; a[n + 1] = a[n];

        int prefix  = 0, sufix = 0;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]) break;
            prefix = i;
        }
        for(int i=n;i >= 1;i--){
            if(a[i]!=a[i+1]) break;
            sufix = i;
        }
        int ans = min( n-prefix, sufix-1);
        if(a[prefix] == a[sufix]) ans = min(ans, sufix - prefix - 1);
        if(sufix == 1 && prefix == n) ans =0;

        cout << ans << "\n";
    }
    return 0;
}

