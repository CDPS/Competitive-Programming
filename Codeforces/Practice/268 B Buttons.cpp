#include <bits/stdc++.h>

using namespace std;

int t =1, n;

int solve(){

    cin >> n;

    int ans = 0;
    for(int i=0; i< n; i++)
        ans += i*(n-i) + 1;

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << solve()  << "\n";

    return 0;
}



