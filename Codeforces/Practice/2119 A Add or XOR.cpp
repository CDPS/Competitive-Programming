#include <bits/stdc++.h>

using namespace std;

int solve(){
    int a, b, x, y;
    cin >> a >> b >> x >> y ;
    if(a > b && a-b > 1) return -1;
    if(a > b && a-b == 1 && a%2==0) return -1;
    if(a > b && a-b == 1 && a%2) return y;

    int ans = 0;
    for(int i=a;i<b;i++){
        if(i%2) ans+=x;
        else ans+= min(x, y);
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
