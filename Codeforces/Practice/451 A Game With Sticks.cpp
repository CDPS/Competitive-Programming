#include <bits/stdc++.h>

using namespace std;

int t =1, n, m;

bool solve(){

    cin >> n >> m;
    return min(n,m)%2;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << (solve()? "Akshat" : "Malvika" ) << "\n";

    return 0;
}



