#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n;

long long solve(){

    cin >> n;

    int pow = 1, digits = 1;
    long long ans = 0;
    while(pow <= n){

        int l = pow;
        int h = (pow*10)-1;

        if(n >  h )
            ans+= (h-l+1ll)*digits;
        else
            ans+= (n-l+1ll)*digits;

        pow*=10;
        digits++;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}

