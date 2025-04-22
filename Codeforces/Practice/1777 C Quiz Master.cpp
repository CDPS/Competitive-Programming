#include <bits/stdc++.h>

using namespace std;

int oo = 1e9;
int n, m;
int a[100000];
unordered_map<int, int> mp;

void add(int x){
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            if(i<=m) mp[i]++;
            if(x/i != i && x/i<= m) mp[x/i]++;
        }
    }
}

void del(int x){
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            if(i<=m && --mp[i]==0) mp.erase(i);
            int d = x / i;
            if(d != i && d<= m && --mp[d]==0) mp.erase(d);
        }
    }
}

bool check(){ return mp.size()== m;}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){

        cin >> n >> m;

        mp.clear();
        for(int i=0;i< n; i++) cin >> a[i];
        sort(a, a+ n);

        int ans = oo;
        for(int i=0, j = 0; j < n ; j++){
            add(a[j]);
            while(i < n && check()){
                ans= min(ans, a[j]-a[i]);
                del(a[i++]);
            }
        }

        cout << (ans==oo? -1 : ans)  << "\n";
    }

    return 0;
}
