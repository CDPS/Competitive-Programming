#include <bits/stdc++.h>

using namespace std;

struct node{
    int l, r, idx;
    node(int l, int r,int idx) : l(l), r(r), idx(idx){}
    bool operator < (const node &a) {
        if(l == a.l)
            return r > a.r;
        return l < a.l;
    }
};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, l, r;
    cin >> n;

    vector<node> v;
    for(int i=0;i<n;i++){
        cin >> l >> r;
        v.push_back(node(l,r, i+1));
    }

    sort(v.begin(), v.end());

    int maxi  = v[0].r;
    int sol1  = v[0].idx, sol2 = -1;
    bool flag = false;
    for(int i=1; i<n && !flag; i++){
        if(v[i].r > maxi)
            maxi = v[i].r, sol1 = v[i].idx;
        else if(v[i].r <= maxi)
            sol2 = v[i].idx, flag = true;
    }

    if(flag)
        cout << sol2 << " " << sol1 << "\n";
    else
        cout <<  -1 << " " << -1 << "\n";
    return 0;
}
