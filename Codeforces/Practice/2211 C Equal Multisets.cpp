#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int a[200001];
int b[200001];

bool solve(){

    cin >> n >> k;

    for(int i=0; i < n ; i++) cin >> a[i];
    for(int i=0; i < n ; i++) cin >> b[i];

    int L = n - k, R = k - 1;

    for(int i = 0 ; i < L ; i++)
        if (b[i] != -1 && b[i] != a[i])
            return false;
    for(int i = R + 1 ;  i < n ; i++)
        if (b[i] != -1 && b[i] != a[i])
            return false;

    vector<bool> required(n + 1, false);
    vector<bool>     seen(n + 1, false);

    for(int i=L; i <= R; i++ )
        required[ a[i] ] = true;

    for(int i=L; i <= R; i++ ){
        if(b[i] != -1) {
            if(!required[b[i]])  return false;
            if(seen[b[i]])  return false;
            seen[b[i]] = true;
        }
    }

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << ( solve()? "YES" : "NO" ) << "\n";
}
