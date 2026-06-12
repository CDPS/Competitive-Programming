#include <bits/stdc++.h>

using namespace std;

int t = 1, s, k, m;

int solve(){

    cin >> s >> k >> m;

    int div  = m/k;

    if(s >= k)
        return (div%2 == 0)? s - m%k : k - m%k;

    return (m%k > s)? 0 : s - m%k;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}


