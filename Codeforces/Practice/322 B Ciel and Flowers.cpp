#include <bits/stdc++.h>

using namespace std;

int a,b,c;

int solve(){

    cin >> a >> b >> c;

    int ans = 0;
    for(int i=0;i<=2;i++){

        if(a < i || b < i || c < i)
            continue;

        int r1 = (a-i)/3;
        int r2 = (b-i)/3;
        int r3 = (c-i)/3;

        ans = max(ans, r1 + r2 +r3 +  i);
    }

    return ans ;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
