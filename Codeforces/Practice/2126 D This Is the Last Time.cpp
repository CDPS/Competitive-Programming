#include <bits/stdc++.h>

using namespace std;

pair<int, pair<int, int> > a[100000];

int n, k, l ,r , x;

int solve(){

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> l >> r >> x;
        a[i] = {l, {r,x}};
    }
    sort(a, a + n);

    for(int i=0;i<n;i++){
        if(k >= a[i].first && k<= a[i].second.first && a[i].second.second > k )
            k = a[i].second.second;
    }
    return k;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << "\n";
    return 0;
}


