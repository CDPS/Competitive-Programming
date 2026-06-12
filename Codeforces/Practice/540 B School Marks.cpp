#include <bits/stdc++.h>

using namespace std;

int t = 1, n, k, p, x, y, ai;

void solve(){

    cin >> n >> k >> p >> x >> y;

    int sum = 0, low = 0, high = 0;
    for(int i = 0; i < k; i++){
        cin >> ai;
        if(ai < y ) low++;
        if(ai >=y)  high++;
        sum+= ai;
    }

    int target = n /2;

    if(low > n /2 ){
        cout << -1 << "\n";
        return;
    }

    int req_y = max(0, (n / 2 + 1) - high);
    int req_1 = (n - k) - req_y;

    sum += req_y * y + req_1;

    if(sum > x ){
        cout << -1 << "\n";
        return;
    }

    for(int i = 0; i < req_1; i++) cout << 1 << " ";
    for(int i = 0; i < req_y; i++) cout << y << " ";
    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
