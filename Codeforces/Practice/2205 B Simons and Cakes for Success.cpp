#include <bits/stdc++.h>

using namespace std;

int t, n;

int solve(){

    cin >> n;

    int ans = 1;
    for(int p=2; p*p <= n; p++ ){
        if(n%p == 0){
            ans*= p;
            while(n %p == 0)
                n/=p;
        }
    }

    if (n > 1) ans *= n;

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";
}
