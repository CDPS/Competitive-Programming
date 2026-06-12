#include <bits/stdc++.h>

using namespace std;

int n;

int solve(){

    cin >> n;

    if(n > 0 ) return n;

    return max(n/10,  (n/100)*10  + (n%10) );
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
