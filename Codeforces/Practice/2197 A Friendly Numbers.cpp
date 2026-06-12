#include <bits/stdc++.h>

using namespace std;

int t, n ;

int calc_sum(int x ){
    int sum = 0 ;
    while(x >= 1)
        sum += x%10, x/=10;
    return sum;
}

int solve(){

    cin >> n;

    int ans = 0;
    for(int i=0; i<=81;i++){
        if ( (n+i) - calc_sum(n+i) == n  )
            ans++;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
