#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

vector<ll> f(vector<ll> &a){
    vector<ll> ans;
    for(int i=0;i<a.size()-1;i++)
        ans.push_back(a[i]-a[i+1]);
    return ans;
}

ll solve(){

    cin >> n;
    vector<ll> a(n);

    ll maxi = 0;
    for(int i=0;i<n;i++)
        cin >> a[i], maxi +=a[i];

    if(n == 1)
        return a[0];

    while(a.size() > 1){
        a = f(a);
        ll acc1 = 0, acc2 =0;
        for(int i=0;i<a.size();i++)
            acc1+=a[i], acc2+=a[i]*-1;
        maxi = max({maxi, acc1, acc2});
    }

    return max({maxi,a[0], a[0]*-1});
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
