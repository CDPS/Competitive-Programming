#include <bits/stdc++.h>

using namespace std;

int a[200000];

map<int,int> mp;

void add(int x){ mp[x]++;}
void del(int x){ mp[x]--; if(mp[x]==0) mp.erase(x); }

int main(){

    int n;

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    long long ans = 0;

    for(int i=0, j=0; j<n;j++){
        add(a[j]);
        while(i <n && mp.size() != j-i+1 )
            del(a[i++]);
        ans += j-i+1;
    }

    cout << ans << "\n";

    return 0;
}
