#include <bits/stdc++.h>

using namespace std;

int n, t;
int p[300000];

void solve(){

    cin >> n;

    for(int i=0, j = 0; i< n; i++, j+=3)
        p[j] = i + 1;
    for(int i= (3*n) -1, curr = 3*n; i>=0; i-=3)
        p[i] =  curr--, p[i-1] = curr--;
    for(int i=0; i< 3*n; i++)
        cout << p[i] << " \n"[i==3*n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}


