#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int t =1, n, k;

int home[100001];

void solve(){

    cin >> n;

    vector< pair<int,int> > v(n);
    for(int i=0; i < n; i++)
        cin >> v[i].f >> v[i].s, home[v[i].f]++;

    for(int i=0; i  < n; i++)
        cout << n - 1 + home[v[i].s] << " " << n - 1 - home[v[i].s] << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}

