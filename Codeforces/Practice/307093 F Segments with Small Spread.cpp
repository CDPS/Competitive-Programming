#include <bits/stdc++.h>

using namespace std;

long long a[100000];
int n;
long long k;
map<long long, int> mp;

void add(long long x){ mp[x]++; }
void del(long long x){ if(--mp[x]==0) mp.erase(x); }
bool check(){ return mp.rbegin()->first - mp.begin()->first <= k;}

int main(){

    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> a[i];

    long long ans = 0;
    for(int i=0, j = 0; j < n ; j++){
        add(a[j]);
        while(i < n && !check()) del(a[i++]);
        ans+= j-i+1;
    }

    cout << ans  << "\n";

    return 0;
}
