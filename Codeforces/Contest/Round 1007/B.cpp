#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[500001];

bool check(ll x){
    ll sqr = sqrt(x);
    return sqr*sqr == x;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    ll t, n;
    cin >> t;

    while(t--){

        cin >> n;

        if(check((n*(n+1))/2ll)){
            cout << -1 << "\n";
            continue;
        }

        for(int i=1;i<=n;i++) a[i] = i;

        ll sum = 0;
        for(int i=1;i<=n;i++){
            if(check(sum + a[i]))
                swap(a[i], a[i+1]);
            sum+= a[i];
            cout << a[i] << " \n"[i==n];
        }
    }
    return 0;
}
