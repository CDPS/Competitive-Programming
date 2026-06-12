#include <bits/stdc++.h>

using namespace std;

int t, n, l, h, x;

int solve(){

    cin >> n >> l >> h;

    if(l > h ) swap(l, h);

    vector<int> a;
    for(int i=0;i < n; i++){
        cin >> x;
        if(x <= h)
            a.push_back(x);
    }

    sort(a.begin(), a.end());

    int ans = 0;
    n = a.size();
    for(int i=0; i < n; i++ ){
        if(a[i] <= l && n-i-1 >= i+1)
            ans++;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
