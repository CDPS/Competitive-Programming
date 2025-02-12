#include <bits/stdc++.h>

using namespace std;

struct node{
    long long  sum;
    vector<int> a;
    node(long long sum, vector<int> a) : sum(sum), a(a){}
    bool operator < (const node &a) const{
        return sum > a.sum;
    }
};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t,n,m,x;
    cin >> t;

    while(t--){
        cin >> n >> m;

        vector<node> v;
        for(int i=0;i<n;i++){
            vector<int> a;
            long long sum = 0;
            for(int j=0;j<m;j++){
                cin >> x;
                a.push_back(x);
                sum+=x;
            }
            v.push_back(node(sum,a));
        }

        sort(v.begin(), v.end());

        long long ans =0,sum =0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
               sum+= v[i].a[j], ans+=sum;

        cout << ans << "\n";
    }
    return 0;
}
