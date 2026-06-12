#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m;

void solve(){

    cin >> n >> m;

    if( m < n-1 || m > n*2 + 2){
        cout << - 1 << "\n";
        return;
    }

    if(n - 1 == m || n == m ){
        while(n + m ){
            if(n > 0) n--, cout << 0;
            if(m > 0) m--, cout << 1;
        }
        cout << "\n";
        return;
    }

    if(n == m -1 ){
        while(n + m ){
            if(m > 0) m--, cout << 1;
            if(n > 0) n--, cout << 0;
        }
        cout << "\n";
        return;
    }


    while(n + m){
        if(m == 1 && n == 0)
            cout << 1, n--;
        else if( m == n )
            cout << 10, n--, m--;
        else if(m > n){
            if(m > 0) m-=2, cout << 11;
            if(n > 0) n--,  cout << 0;
        }
    }
    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
