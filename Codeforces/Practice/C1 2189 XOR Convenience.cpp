#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
int p[200001];

void solve(){

    cin >> n;

    p[n]  = 1;
    p[1]  = n- (n%2);

    if(n%2)
        p[n-1]= n;

    for(int i=2; i<=n-2;i+=2)
        p[i] = i + 1, p[i+1] = i;

    for(int i=1;i<=n;i++)
        cout << p[i] << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}


