#include <bits/stdc++.h>

using namespace std;

int t, n;

int solve(){
    cin >> n;
    if(n%2!=0) return 0;
    return (n%2==0) + (n/4);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
