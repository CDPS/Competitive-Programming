#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int solve(){
    cin >> n;
    if(n%3==0)  return 0;
    if(n%3==1)  return 2;
    return 1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

