#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, k;

int a[200000];
int b[200001];

map<int, int> mp;
void add(int x){ mp[x]++; }
void del(int x){ mp[x]--; }
bool check(int x ){ return mp[x] <= b[x];}

ll solve(){

    cin >> n >> k;

    mp = map<int,int>();
    for(int i=0;i<n;i++)
        cin >> a[i], mp[a[i]]++;

    for(auto it =mp.begin();it!=mp.end();it++){
        if(it->second%k != 0 )
            return 0 ;
        b[it->first] = it->second/k;
    }

    ll ans = 0;
    mp = map<int,int>();
    for(int i=0, j = 0; j < n; j++){
        add(a[j]);
        while(i < n && !check(a[j] ))
            del(a[i++]);
        ans+= j-i+1;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
