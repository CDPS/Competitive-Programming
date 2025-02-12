#include <bits/stdc++.h>

using namespace std;

int a[200000];
int t, n, m , x;

bool solve(){
    for(int i=1;i<=n;i++)
        if(a[i] < a[i-1]) return false;
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){
        cin >> n >> m;

        a[0] = -2e9;
        for(int i=0;i<n;i++) cin >> a[i+1];

        cin >> x;
        for(int i=1;i<=n;i++)
            if( min ( a[i], x-a[i]) >= a[i-1])
                a[i] = min ( a[i], x-a[i]);
            else
                a[i] = max ( a[i], x-a[i]);

        cout << (solve()? "YES" : "NO") << "\n";
    }
    return 0;
}
