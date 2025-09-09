#include <bits/stdc++.h>

using namespace std;

int B[200000];

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

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, a, b;

    cin >> t;

    while(t--){

        cin >> n;

        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){
            cin >> a >> b;
            v.push_back({a,b});
        }
        sort(v.begin(), v.end());

        for(int i=0;i<n;i++)
            B[i] = v[i].second;
        sort(B, B + n);

        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
            mp[B[i]] = i + 1;

        Fenwick f(n);

        long long ans = 0;
        for(int i=n-1;i>=0;i--){
            int idx = mp[ v[i].second ];
            ans += f.query(idx -1 );
            f.update(idx, 1);
        }

        cout << ans << "\n";
    }
    return 0;
}
