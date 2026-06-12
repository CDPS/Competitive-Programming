#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int solve(){

    cin >> n ;

    vector<int> v( (n*n) + 1, 0);
    for(int i=0; i < n*n; i++)
        cin >> x, v[x]++;

    for(int i=1; i <= n*n; i++)
        if(v[i] > n*(n-1))
            return false;

    return true;
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}
