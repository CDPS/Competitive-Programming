#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
int a[200001];


bool check(int l, int r){

    vector<bool> check(n + 1);
    for(int i= l; i <=r; i++)
        check[   a[i]] = true;
    for(int i=1; i<= r-l+1; i++)
        if(!check[i]) return false;
    return true;
}

void solve(){

    cin >> n;

    int M = -1;
    for(int i= 1; i <=n; i++)
        cin >> a[i], M = max(M, a[i]);

    set< pair<int, int> > ans;
    if(check( 1, n-M) && check( (n-M) + 1, n))
        ans.insert({n-M, M});
    if(check( 1, M) && check(M+1, n))
        ans.insert({M, n-M});

    cout << ans.size() << "\n";
    for(auto p : ans)
        cout << p.first << " " << p.second << "\n";
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        solve();

    return 0;
}
