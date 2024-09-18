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

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n,m,s,e,p;

    while(cin >> n >> m && (n || m) ){

        Fenwick f(1000001);
        for(int i=0;i<n;i++){
            cin >> s >> e;
            f.update(s+1,1); f.update(e+1,-1);
        }

        for(int i=0;i<m;i++){
            cin >> s >> e >> p;
            while (s < 1000000){
                f.update(s+1,1); f.update(e+1,-1);
                s = min(s + p, 1000000);
                e = min(e + p, 1000000);
            }
        }

        bool ans = true;
        for(int i = 0 ; i <1000001 && ans;i++)
            ans = f.query(i) <=1;

        cout  <<((ans)? "NO CONFLICT":"CONFLICT" ) << "\n";
    }
    return 0;
}
