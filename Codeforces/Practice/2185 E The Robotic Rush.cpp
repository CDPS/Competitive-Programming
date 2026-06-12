#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n , m , k;

ll a[200000];
ll b[200002];

string s;

void solve(){

    cin >> n >> m >> k;
    for(int i=0;i<n;i++) cin >> a[i];

    b[0] = -1e18; b[m+1] = 1e18;
    for(int i=1;i<=m;i++) cin >> b[i];
    cin >> s;

    sort(a, a + n);
    sort(b, b + m + 2);

    vector<vector<int> > dr(k+1);
    vector<vector<int> > dl(k+1);

    for(int i=0;i<n;i++){
        auto it = upper_bound(b, b + m + 1, a[i]);

        ll right = (*it)-a[i];
        ll left =  a[i]-*(it - 1);

        if(right <= k)dr[right].push_back(i);
        if(left  <= k)dl[left ].push_back(i);
    }

    vector<bool> dead(n, 0);
    int l = 0, h = 0, curr = 0, curr_dead = 0;
    for(int i=0;i<k;i++){

        curr = (s[i]=='R')? curr + 1 : curr -1;

        if (curr < 0 && abs(curr) > l) {
            l = abs(curr);
            for(int idx : dl[l])
                if (!dead[idx])
                    dead[idx] = true, curr_dead++;
        }

        if (curr > 0 && abs(curr) > h) {
            h = abs(curr);
            for(int idx : dr[h])
                if (!dead[idx])
                    dead[idx] = true, curr_dead++;
        }

        cout << n - curr_dead << " \n"[i==k-1];
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
