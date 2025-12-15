#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int n;
int a[1000];

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

bool solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    map<int, priority_queue<int> > mp;
    vector<int> B;

    for(int i=1;i <n; i++){
        mp[min(a[i], a[i-1])].push(max(a[i], a[i-1]));
        B.push_back(min(a[i], a[i-1]));
        B.push_back(max(a[i], a[i-1]));
    }

    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    int m = B.size();
    map<int, int> mp2;
    for(int i=0;i< m;i++)
        mp2[B[i]] = i + 1;

    Fenwick f(m);

    for(auto it = mp.begin(); it != mp.end(); it++){
        vector<int> curr;
        priority_queue<int> pq = it->second;
        while(!pq.empty()){
            int u = pq.top(); pq.pop();
            if(f.query(mp2[ u ] -1 ) - f.query( mp2[it->first] ) >0)
                return true;
            curr.push_back(u);
        }
        for(int i=0;i<curr.size();i++)
             f.update(mp2[curr[i]], 1);
    }

    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << ( solve()? "yes" : "no" ) << "\n" ;

    return 0;
}
