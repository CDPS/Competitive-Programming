#include <bits/stdc++.h>

using namespace std;

struct node{
    int x, r;
    node(int x,int r): x(x), r(r){}
    bool operator < (const node &a)const{
        if(x==a.x)
            return r > a.r;
        return x < a.x;
    }
};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,m,x;
    cin >> t;

    while(t--){

        cin >> n;

        vector<node> v;
        for(int i=0;i<n;i++){
            cin >> m;
            int maxi =-1;
            for(int j=0;j<m;j++)
                cin >> x, maxi = max(x-j, maxi);
            v.push_back(node(maxi,m));
        }
        sort(v.begin(), v.end());

        int ans = v[0].x, current = 0;
        for(int i=1;i<v.size();i++){
            current += v[i-1].r;
            ans = max(ans, v[i].x - current);
        }

        cout << ans + 1 << "\n";
    }

    return 0;
}
