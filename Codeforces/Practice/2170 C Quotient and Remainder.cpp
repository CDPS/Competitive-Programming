#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll  k;
ll  q[200000], r[200000];

bool check(int x){
    for(int i = 0; i < x; i++)
        if ((q[i] + 1) * (r[x - 1 - i] + 1) > k + 1)
            return false;
    return true;
}

int solve(){

    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> q[i];
    for(int i=0;i<n;i++) cin >> r[i];

    sort(q, q + n);
    sort(r, r + n);

    int l=0, h = n, m;
    while(l<h){
        m = l + ( (h-l+1)/2 );
        if(!check(m))
             h = m-1;
        else l = m;
    }

    return l;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
