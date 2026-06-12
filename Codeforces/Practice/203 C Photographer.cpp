#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

int t = 1, n, w, a, b;

struct node{

    int xi, yi, ci, idx;
    node(int xi, int yi, int idx) : xi(xi), yi(yi), idx(idx){
        ci = (xi* a) + (yi * b);
    }
    bool operator < (const node & a){ return ci < a.ci; }
};

int xi, yi;

void solve(){

    cin >> n >> w >> a >> b;

    vector<node> v;
    for(int i=1; i<=n; i++){
        cin >> xi >> yi;
        v.push_back(node(xi, yi, i));
    }

    sort(v.begin(), v.end());

    vector<int> ans;
    for(int i=0;i < n ; i++){
        if(w >= v[i].ci)
            ans.push_back(v[i].idx), w-=v[i].ci;
    }

    cout << ans.size() << "\n";
    for(int i=0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i==ans.size()-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
