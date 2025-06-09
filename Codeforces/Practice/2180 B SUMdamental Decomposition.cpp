#include <bits/stdc++.h>

using namespace std;

int solve(int n){

    if(n%2==0) return n;
    return n-2 +  2 + 3;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;

    cin >> t;

    while(t--){

        cin >> n >> x;

        int ans = solve( x==0? n : n -1);

        cout <<(ans == -1? ans : x + ans )<< "\n";
    }

    return 0;
}



