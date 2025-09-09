#include <bits/stdc++.h>

using namespace std;

struct node{
    int l, r, w;
    node(int l, int r, int w):l(l),r(r), w(w){}
    bool operator < (const node &a) const{
        return r < a.r;
    }
};

long long dp[200001];
int n;
vector<node> v;

int lowerbound(int target) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if (v[mid].r <= target) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int a,b,p;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b >> p;
        v.push_back(node(a,b,p));
    }
    v.push_back({0,0,0});
    sort(v.begin(), v.end());


    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int prev = lowerbound(v[i].l -1);
        dp[i] = max(dp[i-1], dp[prev] + v[i].w );
    }

    cout << dp[n] << "\n";

    return 0;
}
