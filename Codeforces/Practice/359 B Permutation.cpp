#include <bits/stdc++.h>

using namespace std;

int t = 1, n, k;
int p[100001];

void solve(){

    cin >> n >> k;

    for(int i= 1; i<=2*n;i++)
        p[i] = i;

    for(int i=1, j=0; j<k && i<=2*n;i+=2, j++)
        swap(p[i], p[i+1]);

    for(int i= 1; i<=2*n;i++)
        cout << p[i] << " \n"[i==2*n];
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();
}
