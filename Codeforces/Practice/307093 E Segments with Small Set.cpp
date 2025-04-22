#include <bits/stdc++.h>

using namespace std;

int a[200000];
int acc = 0, n, k;
map<int, int> mp;

void add(int x){ if(++mp[x]==1) acc++; }
void del(int x){ if(--mp[x]==0) acc--; }
bool check(){return acc <= k;}

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
