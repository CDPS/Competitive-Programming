#include <bits/stdc++.h>

using namespace std;

bool ans[100000];

struct node{
    int l, r, idx;
    node(int l, int r,int idx) : l(l), r(r), idx(idx){}
    bool operator < (const node &a) {
        if(l == a.l) return r > a.r;
        return l < a.l;
    }
};

bool check(int n){
    bool init = ans[0];
    for(int i=1;i<n;i++)
        if(ans[i]!=init) return false;
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, l, r;

    cin >> t;
    while(t--){

        cin  >> n;

        vector<node> v;
        for(int i=0;i<n;i++)
            cin >> l >> r, v.push_back(node(l,r, i));
        sort(v.begin(), v.end());

        int maxi  = v[0].r;
        bool sets = true;
        ans[ v[0].idx] = sets;
        for(int i=1; i<n; i++){
            if( v[i].l <= maxi) ans[v[i].idx] = sets;
            if( v[i].l  > maxi) sets = !sets, ans[v[i].idx] = sets, maxi = v[i].r;
            if( v[i].r  > maxi) maxi = v[i].r;
        }

        if(check(n)){
            cout << -1 << "\n";
            continue;
        }

        for(int i=0;i<n;i++)
            cout << ans[i] + 1 << " \n"[i==n-1];
    }
    return 0;
}
