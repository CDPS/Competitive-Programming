#include <bits/stdc++.h>

using namespace std;

int a[100000];
int n, c;

map<int, int> mp;
void add(int x){ mp[x]++;}
void del(int x){if(--mp[x]==0) mp.erase(x);}

int solve(){

    cin >> c >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    mp = map<int,int>();
    for(int i=0;i<=c;i++) add(a[i]);

    int ans = mp.rbegin()->first;
    for(int i=c+1;i<n;i++){
        del(a[i-c-1]);
        add(a[i]);
        ans= min(ans, mp.rbegin()->first);
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
