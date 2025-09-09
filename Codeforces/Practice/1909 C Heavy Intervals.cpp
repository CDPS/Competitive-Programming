#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, t;
ll x;

ll solve(){

    cin >> n;

    vector<ll> c(n);
    vector<ll> ranges(n);
    vector<pair<ll,ll> > a;

    for(int i=0;i<n;i++) cin >> x, a.push_back({x, 0});
    for(int i=0;i<n;i++) cin >> x, a.push_back({x, 1});
    for(int i=0;i<n;i++) cin >> c[i];

    sort(a.begin(), a.end());

    stack<int> st;
    for(int i=0, j=0;i<a.size();i++){
        if(a[i].second)
            ranges[j++]= a[i].first - st.top(), st.pop();
        else
            st.push(a[i].first);
    }

    ll ans = 0;
    sort(ranges.begin(), ranges.end());
    sort(c.begin(), c.end(), greater<ll>());

    for(int i=0;i<n;i++)
        ans+= ranges[i]*c[i];

    return ans;
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
