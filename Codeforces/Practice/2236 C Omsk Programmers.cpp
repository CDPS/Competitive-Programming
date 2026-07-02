#include <bits/stdc++.h>

using namespace std;

int t, a, b, x;
int solve(){

    cin >> a >> b >> x;

    vector< pair<int,int> > va, vb;

    int curr = 0;
    while(a > 0 )
        va.push_back({a, curr++}), a/=x;
    va.push_back({0, curr});

    curr = 0;
    while(b > 0 )
        vb.push_back({b, curr++}), b/=x;
    vb.push_back({0, curr});

    int n = va.size();
    int m = vb.size();
    int ans = 1e9;
    for(int i=0 ; i < n;  i++)
        for(int j = 0; j< m; j++)
            ans = min(ans, abs(vb[j].first - va[i].first) + va[i].second + vb[j].second  );
        
    return ans;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        cout << solve() << "\n";
    return 0;
}