#include <bits/stdc++.h>

using namespace std;

int t =1, maxi, mini;

int solve(){

    cin >> maxi >> mini;

    int ans = 0;
    while(maxi > 0 && mini > 0){

        if(mini > maxi) swap(mini, maxi);

        mini++;
        maxi-=2;

        if(maxi < 0) break;

        ans++;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
