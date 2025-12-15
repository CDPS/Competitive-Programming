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

int solve(){

int n, l, r;

    cin >> n;

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        cin >> l >> r;
        v.push_back({l,r});
    }

    sort(v.begin(), v.end(), [&](auto &A, auto &B){
        if(A.first == B.first )
            return A.second > B.second;
        return A.first < B.first;
    });

    for(int i=0;i<n;i++)
        B[i] = v[i].second;
    sort(B, B + n);

    int m = unique(B, B + n) - B;

    unordered_map<int, int> mp;
    for(int i=0;i<m;i++)
        mp[B[i]] = i + 1;

    Fenwick f(m);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = mp[ v[i].second ];
        ans += (f.query(m) - f.query(idx-1) > 0);
        f.update(idx, 1);
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}

