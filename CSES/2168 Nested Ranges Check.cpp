#include <bits/stdc++.h>

using namespace std;

struct range{
    int l, r, idx;
    range(int l,int r, int idx) : l(l), r(r), idx(idx){}
    bool operator < (const range &a) const{
        if(l == a.l) return r > a.r;
        return l < a.l;
    }
};

bool a[200000];
bool b[200000];
vector<range> v;

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, r;

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> l >> r, v.push_back(range(l, r, i));
    sort(v.begin(), v.end());


    int mini = v[n-1].r;
    for(int i=n-2;i>=0;i--){
        if(v[i].r >= mini ) a[v[i].idx] = true;
        if(v[i].r < mini)
            mini = v[i].r;
    }

    int maxi = v[0].r;
    for(int i=1;i<n;i++){
        if(v[i].r <= maxi ) b[v[i].idx] = true;
        if(v[i].r > maxi)
            maxi = v[i].r;
    }

    for(int i=0;i<n;i++)
        cout << a[i] << " \n"[i==n-1];
    for(int i=0;i<n;i++)
        cout << b[i] << " \n"[i==n-1];

    return 0;
}
