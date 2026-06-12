#include <bits/stdc++.h>

using namespace std;

int t = 1, n;

int solve(){
    cin >> n;
    return (n%2)? 0 :  (n-1)/4 ;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << solve() << "\n";

    return 0;
}
