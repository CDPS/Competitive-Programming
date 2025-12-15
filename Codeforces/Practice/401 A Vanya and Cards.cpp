#include <bits/stdc++.h>

using namespace std;

int n, k, x;

int solve(){

    cin >> n >> k;

    int sum  = 0;
    for(int i=0;i<n;i++)
        cin >> x, sum += x;

    sum = abs(sum);
    int ans = 0;
    for(int i=k;i>=1;i--){
       while(sum >= i)
            ans++, sum-=i;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}

