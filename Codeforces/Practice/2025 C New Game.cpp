#include <bits/stdc++.h>

using namespace std;

int a[200000];
int acc, n, k;
map<int, int> mp;

void add(int x){ if(++mp[x]==1) acc++; }
void del(int x){ if(--mp[x]==0) acc--; }

bool check(){
    if (acc < 2) { return true; }
    auto it = mp.rbegin();
    int k1 = it->first; ++it;
    int k2 = it->first;
    return acc <= k && k1-k2 <=1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){

        cin >> n >> k;

        for(int i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);

        int ans = 0;
        mp.clear();
        acc=0;

        for(int i=0, j = 0; j < n ; j++){
            add(a[j]);
            while(i < n && !check()) del(a[i++]);
            ans= max( ans, j-i+1);
        }

        cout << ans << "\n";
    }

    return 0;
}
