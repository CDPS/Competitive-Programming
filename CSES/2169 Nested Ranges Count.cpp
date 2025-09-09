#include <bits/stdc++.h>

using namespace std;

class Fenwick{

    public:
    vector <int> tree;
    int maxVal;

    Fenwick(int n) {
        maxVal=n;
        tree= vector<int>(maxVal+1,0);
    }

    int query(int idx){
        int sum =0;
        while(idx > 0)
            sum+= tree[idx], idx -= (idx & -idx);
        return sum;
    }

    void update(int idx, int val){
        while(idx<=maxVal)
            tree[idx]+=val, idx+= (idx & -idx);
    }
};

int B[200000];
int ans1[200000];
int ans2[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, l, r;

    cin >> n;

    vector<pair< int, pair<int,int> > > v;
    for(int i=0;i<n;i++){
        cin >> l >> r;
        v.push_back({l,{r, i}});
    }
    sort(v.begin(), v.end(), [&](auto &A, auto &B){
        if(A.first == B.first )
            return A.second.first > B.second.first;
        return A.first < B.first;
    });


    for(int i=0;i<n;i++)
        B[i] = v[i].second.first;
    sort(B, B + n);

    int m = unique(B, B + n) - B;

    unordered_map<int, int> mp;
    for(int i=0;i<m;i++)
        mp[B[i]] = i + 1;

    Fenwick f(m);
    for(int i=n-1;i>=0;i--){
        int idx = mp[ v[i].second.first ];
        ans1[ v[i].second.second] = f.query(idx);
        f.update(idx, 1);
    }

    f = Fenwick(m);
    for (int i = 0; i < n; i++) {
        int idx = mp[ v[i].second.first ];
        ans2[ v[i].second.second] = f.query(idx);
        f.update(idx+1, -1);
        f.update(1,1);
    }

    for(int i=0;i<n;i++)
        cout << ans1[i] << " \n"[i==n-1];

    for(int i=0;i<n;i++)
        cout << ans2[i] << " \n"[i==n-1];

    return 0;
}
