#include <bits/stdc++.h>

using namespace std;

int a[100000];
int acc = 0, n, k;
map<int, int> mp;

void add(int x){ if(++mp[x]==1) acc++; }
void del(int x){ if(--mp[x]==0) acc--; }

void solve(){

    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];

    int curr = 1e9, r = -1, l = -1;
    for(int i=0, j = 0; j < n ; j++){
        add(a[j]);

        while(acc > k) del(a[i++]);

        while(acc == k && mp[a[i]] > 1) {
            del(a[i]);
            i++;
        }
        if(acc == k && j-i+1 < curr)
            curr = j-i+1, l = i, r= j;
    }

    if(l==-1 && r == -1)
        cout << l << " " << r<< "\n";
    else
        cout << l + 1  << " " << r + 1 << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
