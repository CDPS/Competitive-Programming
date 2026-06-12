#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int t = 1, n, m, l, r, ai, bi;

int solve(){

    cin >> n >> m >> l >> r;

    vector<int> pfx(20005, 0);
    for(int i=0;i < n; i++){
        cin >> ai >> bi;
        for(int j = ai; j <=bi; j++)
            pfx[j] = 1;
    }

    vector<pair<int,int> > v(m);
    for(int i=0; i < m; i++)
        cin >> v[i].f >> v[i].s;

    for(int i= 1;i <= 2000; i++)
        pfx[i] += pfx[i-1];

    int ans = 0;
    for(int i=l; i<=r; i++){
        for(int j=0; j < m; j++){
            int C = v[j].f + i;
            int D = v[j].s + i;
            if(pfx[D] - (C > 0 ? pfx[C - 1] : 0) > 0){
                ans++; break;
            }
        }
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
