#include <bits/stdc++.h>

using namespace std;

int t, n, x, y, z;

int calc(int a, int b){
    return (a + b - 1) / b;
}

int solve(){
    
    cin >> n >> x >> y >> z;
    
    int ans = calc(n, x + y);
    if(z * x <= n)
        ans = min(ans, calc(n- x*z, x + 10* y) + z);
    
    return ans;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        cout << solve() << "\n";
    
    return 0;
}