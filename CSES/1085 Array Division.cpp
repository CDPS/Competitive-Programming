#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
ll a[200000];

bool check(ll x){
    ll acc = 0; int sets = 1;
    for (int i = 0; i < n; i++) {
        if (acc + a[i] > x)
            sets++, acc = 0;
        acc += a[i];
    }
    return sets <= k;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;

    ll l = 0, h = 0, m;
    for(int i=0;i<n;i++) cin >> a[i], l = max(l, a[i]), h += a[i];

    while(l< h){
        m = l + ( (h-l)/2 );
        if(check(m))
             h = m;
        else l = m +1;
    }


    cout << l << "\n";

    return 0;
}

