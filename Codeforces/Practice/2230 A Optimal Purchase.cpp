#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;

ll n, a, b;

ll solve(){
    cin >> n >> a >> b;
    return min({  n*a, ((n/3)*b) + ((n%3!=0)*b), ((n/3)*b) + ((n%3)*a) });
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}