#include <bits/stdc++.h>

using namespace std;

int t, n, k, q;

void solve(){

    cin >> n >> k >> q;

    vector<int> a(n + 1, 0);

    int op, l, r;
    while(q--){
        cin >> op >> l >> r;
        for(int i=l; i<= r;i++){
            if(a[i] == 0 ) a[i] = op;
            if(a[i] == 1 && op == 2) a[i]+= op;
            if(a[i] == 2 && op == 1) a[i]+= op;
        }
    }

    int curr = 0;
    for(int i=1;i<=n;i++ ){

        if(a[i] == 2){
            a[i] = (curr)% k; curr++;
            continue;
        }
        curr = 0;

        if(a[i] == 1){
            a[i] = k;
            continue;
        }
        if(a[i] == 3){
            a[i] = k + 1;
            continue;
        }
    }

     for(int i=1;i<=n;i++)
        cout << a[i] << " \n"[i==n];
}

int main(){

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
