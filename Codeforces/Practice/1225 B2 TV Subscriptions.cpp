#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, k, d;
int a[200000];

map<int, int> mp;

void add(int x){ mp[x]++;}
void del(int x){if(--mp[x]==0) mp.erase(x);}

int solve(){

    cin >> n >> k >> d;

    for(int i=0;i<n;i++) cin >> a[i];

    mp = map<int,int>();

    for(int i=0;i<d;i++) add(a[i]);

    int ans = mp.size();
    for(int i=d;i<n;i++){
        del(a[i-d]);
        add(a[i]);
        ans= min(ans, (int)mp.size());
    }

    return ans;
}


int main(){

     cin.sync_with_stdio(false); cin.tie(NULL);

     cin >> t;
     while(t--)
        cout << solve() << "\n";
}
