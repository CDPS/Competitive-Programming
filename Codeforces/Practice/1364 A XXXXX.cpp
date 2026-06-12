#include <bits/stdc++.h>

using namespace std;

int t, n, m;
int a[100000];

int solve(){

    cin >> n >> m;

    int sum = 0;
    for(int i=0; i < n; i++)
        cin >> a[i], sum = (sum + (a[i]%m) )%m;

    if(sum !=0) return n;

    int l = 0;
    while(l < n && a[l]%m ==0)
        l++;

    int r = n-1;
    while(r >= 0 && a[r]%m ==0)
        r--;

    if(r==-1) return -1;

    return max( n-l-1, r);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

